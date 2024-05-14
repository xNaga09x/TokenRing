Token Ring Network Simulation

Description:

The Token Ring Network Simulation is a C++ application that simulates the activity of a Token Ring network consisting of 10 computers. In a Token Ring network, a single token moves sequentially from one computer to another, allowing message transmission in a unidirectional manner.

Each token is characterized by:

Source IP address
Destination IP address
Message content
Flag indicating whether the token is free or occupied
Flag indicating whether the token has reached its destination
Each computer in the network has a buffer and an IP address represented as a string. Source and destination computers are randomly generated for each simulation step, ensuring they are not the same.

Simulation Steps:

Each simulation step represents the movement of the token from one computer to another.
At each step, a source and destination computer are randomly generated.
If a computer receives the token, it checks whether its own IP address matches the destination IP address in the token.
If the destination matches, the computer copies the message into its buffer, sets the token flag indicating message arrival, and passes the token to the next computer until it reaches the source.
After the token is set free, any computer in the network can grab it, initiating the next transmission cycle.

Example Simulation Output (Step-by-Step Display):
C0(155.109.13.108) -> null
C1(151.91.11.141) -> null
C2(68.151.34.159) -> null
C3(116.138.160.38) -> null
C4(117.195.33.55) -> null
C5(192.111.251.134) -> null
C6(2.2.152.150) -> null
C7(25.114.37.167) -> null
C8(177.179.25.15) -> null
C9(75.196.178.105) -> null
Source: C4 Destination: C9
C4: Move token
C5: Move token
C6: Move token
C7: Move token
C8: Move token
C9: Arrived at destination
C9: Move token
C0: Move token
C1: Move token
C2: Move token
C3: Move token
C4: Arrived back
C0(155.109.13.108) -> null
C1(151.91.11.141) -> null
C2(68.151.34.159) -> null
C3(116.138.160.38) -> null
C4(117.195.33.55) -> null
C5(192.111.251.134) -> null
C6(2.2.152.150) -> null
C7(25.114.37.167) -> null
C8(177.179.25.15) -> null
C9(75.196.178.105) -> null;test message
Source: C0 Destination: C5
C4: Move token
C5: Move token
C6: Move token
C7: Move token
C8: Move token
C9: Move token
C0: Token grabbed
C0: Move token
C1: Move token
C2: Move token
C3: Move token
C4: Move token
C5: Arrived at destination
C5: Move token
C6: Move token
C7: Move token
C8: Move token
C9: Move token
C0: Arrived back
C0(155.109.13.108) -> null
C1(151.91.11.141) -> null
C2(68.151.34.159) -> null
C3(116.138.160.38) -> null
C4(117.195.33.55) -> null
C5(192.111.251.134) -> null;test message
C6(2.2.152.150) -> null
C7(25.114.37.167) -> null
C8(177.179.25.15) -> null
C9(75.196.178.105) -> null;test message

The simulation provides a step-by-step display of token movement between computers, and the message retrieval process at the destination computer. Each step demonstrates the transmission cycle within the Token Ring network, ensuring accurate and efficient message delivery.
