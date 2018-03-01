function load_connections(project_name)
    clear elems;

    sensors = queryconnections('Sensors', project_name);
    actuators = queryconnections('Actuators', project_name);

    elems(1:numel(sensors)) = Simulink.BusElement;

    [elems.Name] = deal(sensors.Name);
    [elems.DocUnits] = deal(sensors.DocUnit);
    [elems.Description] = deal(sensors.Description);

    sensors_bus = Simulink.Bus;
    sensors_bus.HeaderFile = '';
    sensors_bus.Description = sprintf('Sensors for %s plant', project_name);
    sensors_bus.DataScope = 'Auto';
    sensors_bus.Alignment = -1;
    sensors_bus.Elements = elems;
    assignin('base', 'sensors_bus', sensors_bus)

    assignin('base', 'sensors', sensors);
    assignin('base', 'actuators', actuators);

end

function return_val = queryconnections(type, project_name)

    %Set preferences with setdbprefs.
    setdbprefs('DataReturnFormat', 'structure');
    setdbprefs('NullNumberRead', 'NaN');
    setdbprefs('NullStringRead', '');


    %Make connection to database.  Note that the password has been omitted.
    %Using ODBC driver.
    conn = database.ODBCConnection(sprintf('connections_%s', project_name), '', '');

    sqlquery = sprintf('SELECT * FROM %s', type);

    %Read data from database.
    curs = exec(conn, sqlquery);

    curs = fetch(curs);
    close(curs);

    %Assign data to output variable
    tmp = curs.Data;

    fnames = fieldnames(tmp);
    for j = 1:numel(fnames) 
        for i = 1:numel(tmp.Channel)
            data = tmp.(fnames{j})(i);
            if iscell(data)
                data = cell2mat(data);
            end
            return_val(i).(fnames{j}) = data; 
        end
    end

    %Close database connection.
    close(conn);

    %Clear variables
    clear curs conn

end