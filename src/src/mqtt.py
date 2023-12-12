import time
import sys
import paho.mqtt.client as paho
from paho import mqtt

# setting callbacks for different events to see if it works, print the message etc.
def on_connect(client, userdata, flags, rc, properties=None):
    print("CONNACK received with code %s." % rc)

# with this callback you can see if your publish was successful
def on_publish(client, userdata, mid, properties=None):
    print("mid: " + str(mid))

# print which topic was subscribed to
def on_subscribe(client, userdata, mid, granted_qos, properties=None):
    print("Subscribed: " + str(mid) + " " + str(granted_qos))

# print message, useful for checking if it was successful
def on_message(client, userdata, msg):
    print(msg.topic + " " + str(msg.qos) + " " + str(msg.payload))

# using MQTT version 5 here, for 3.1.1: MQTTv311, 3.1: MQTTv31
# userdata is user defined data of any type, updated by user_data_set()
# client_id is the given name of the client
client = paho.Client(client_id="", userdata=None, protocol=paho.MQTTv5)
client.on_connect = on_connect

# enable TLS for secure connection
client.tls_set(tls_version=mqtt.client.ssl.PROTOCOL_TLS)
# set username and password
client.username_pw_set("grp1_user", "grp1_pass")
# connect to HiveMQ Cloud on port 8883 (default for MQTT)
client.connect("b249f3306b2142cc9ac461939d5b0b70.s2.eu.hivemq.cloud", 8883)

# setting callbacks, use separate functions like above for better visibility
client.on_subscribe = on_subscribe
client.on_message = on_message
client.on_publish = on_publish

# subscribe to all topics of encyclopedia by using the wildcard "#"print(data2)
print("b")

data = sys.stdin.read()
print("a")
data2=""
data3=""
if data[0]=='1':
    data2=data[2:7]
    data3=data[8:13]
    print(data2)
    client.publish("MqttTopics/Temperature", payload=data2, qos=1)
    client.publish("MqttTopics/Humidity", payload=data3, qos=1)
elif data[0]=='2':
    data2=data[2:7]
    client.publish("MqttTopics/CO2", payload=data2, qos=1)
#print("msg : ",data2," ",data3,"\n")
# a single publish, this can also be done in loops, etc.
# loop_forever for simplicity, here you need to stop the loop manually
# you can also use loop_start and loop_stop
#client.loop_forever()