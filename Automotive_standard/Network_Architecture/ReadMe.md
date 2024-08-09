# Current Network Architecture in Automotive

- Ethernet Protocol in the Market

### OSI Architecture (Open Systems Interconnection)
- The OSI model is a conceptual framework that helps us understand and design network protocols and communication systems. It breaks down the complex process of network communication into seven distinct layers, each with its own specific role.

1. Physical Layer --> Define How data will transmit through wires/wirless(WIFI)

2. Data Link Layer --> his layer determines how data is formatted for transmission across the network. It handles the packaging of data into frames and manages error detection and correction. For instance, while the Physical Layer transmits raw bits, the Data Link Layer ensures that the data, such as the value 0xAA, is properly framed and formatted according to standardized protocols before sending it over the network.

ex:CAN - LIN - Ethernet --> Data - Physical layer 
- Till now we didn't go to internet so if we want we need to used Network
- Frame = Ethernet with physical Layer
3. Network --> Concept of connecting multiple network together to connect them together [IP-4,IP-6] --> This Layer is over Datalink Layer.
- The Power of Ethernet that Any network protocol [IPv4,IPv6] can be over Ethernet
* Frame = Ethernet + IPv4
4. Transport --> [TCP - UDP]
* Frame = Ethernet + IPv4 + TCP
5. Session

6. Presentation 

7. Application --> HTTP , FTP, DNS,....

كل layer بتستخدم اللى تحتها لحد  ما نوصل للفيزيكال

- So to call google.com --> (https) go and call TCP then (TCP) call IPv4, so (IPv4) call (Ethernet). 
- MAC Address is unique for my Device
-----------------------------------------------------------------------
|   Ethernet Protocol | IPv4 | UDP header | https header | https data |
|                     |      |            |              |            |
-----------------------------------------------------------------------
                      |         This is the Payload of Ethernet       |
                      -------------------------------------------------
                             | This is the Payload of IPv4            |
                             ------------------------------------------

- This is the essential Layers and main layout of the protocol.
- Ethernet Gives capability to send 1500 byte , Speed = 200G. 
- Why ethernet wasn't used in Automotive years ago?
--> Broad-R Reach --> Just two wires connected between 2 nodes can be full duplex, So ethernet of Automtive just 2 wires and that's the reason Ethernet of existance of Ethernet in Automotive industry.

- Ethernet of Laptop is the same in Automotive but the difference between them is Physical layer but they are similar in data link layer -Let it to be similar not but in general they are not so Similar there is some difference between them based on Standered due to Hardware but still data frame are the same- [شكل ال فريم] and so on. 

------------------------------------------------------------------------------------------------

### TCP/IP Architecture

1. Link Layer --> THis Layer Group to layers of OSI in on layer which are Data and Physical

2. Internet --> Network

3. Transport

4. Application

------------------------------------------------------------------------------------------------

### Let's Start with Physical layer in Depth

- We have 2 Mc such as RPI microcontroler So in our Phyical layer ther are some components:
1. Ethernet Caple    
2. Phy --> Which is the Socket that I enter Ethernet capble in. such as RG405
3. MAC peripheral that are connected to the PHy
                  -------
                -|       |-
- Phy --->      -|  PHy  |-  So The right side of PHY is MDI (Media Dependant interface)
                -|       |-     The  Left side is MII (Media Independant interface)
                  -------
- So PHY of thype RG405 Can only talk with RG405 aslo through MDI, or it can talk with another type by using converter in between.
- MAC talks with PHY through MII.

- PHY has Layers:
1. PCS --> Physical coding sublayer and it's responsible of coding and decoding of data such as (3B2), It's in side of MAC
2. PMA --> Physical Meduim Attachment, It's responsible of Identifying the data that I received.
            So it cancel the echo so we said that we can send and receive at same time at the same two wires, By recieving the full package of data the I sent and received then I cancel from this data, the one I have sent --> That's How I know the what's the received data
    