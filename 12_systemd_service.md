# OPC UA Server as systemd linux service

Setup up your OPC UA server as systemd service to ensure automatic start and execution of the server.

Create a systemd service file

``` {.Bash language="Bash"}
sudo nano /etc/systemd/system/opcua.service ```

with the following content 

``` {.Bash language="Bash"}
[Unit]
Description=OPC UA Server Service
After=network.target
StartLimitIntervalSec=0
[Service]
Type=simple
Restart=always
RestartSec=5
User=opcua
WorkingDirectory=/home/opcua/PaintingStationBelt/build
ExecStart=/home/opcua/PaintingStationBelt/build/PaintingStationBelt

[Install]
WantedBy=multi-user.target
```

with the individual entries explained:

``` {.Bash language="Bash"}
[Unit]
Description={description of serivce}
After={start this service after the serivce mentioned here}
StartLimitIntervalSec={service start delay}
[Service]
Type=simple 
Restart=always #restart service after crash 
RestartSec=5 #period until restart attempt
User=opcua #user running the service
WorkingDirectory={path to service folder}
ExecStart={path to service executable}

[Install]
WantedBy=multi-user.target #may be executed by any user
```

Register the service with systemd

``` {.Bash language="Bash"}
sudo systemctl daemon-reload
```

The service can now be operated like any other systemd service.

``` {.Bash language="Bash"}
sudo systemctl status opcua.service
```

``` {.Bash language="Bash"}
sudo systemctl is-active opcua.service
```

``` {.Bash language="Bash"}
sudo systemctl start opcua.service
sudo systemctl restart opcua.service 
sudo systemctl stop opcua.service 
```

``` {.Bash language="Bash"}
sudo systemctl enable opcua.service 
sudo systemctl disable opcua.service 
```

``` {.Bash language="Bash"}
sudo journalctl -f -a -uopcua.service
```
