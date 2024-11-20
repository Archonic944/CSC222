# Essence of Object-Oriented Questions

1. What is code rot, and why does it happen?

Code rot is when source code succumbs to viscocity, rigidity, or immobility over time. The "rotted code" is unable to cleanly account for changes in low level details. This happens because low level details are directly integrated instead of fed into an abstraction.


2. What is the design of a software product?

The "design" of a software product (akin to a blueprint in architecture) is the source code. The product is the built binary.

3. What is the essential characteristic of OO design?

The sender of an instruction does not depend on the recipient. The recipient does not depend on the sender. They both depend on an abstraction. The dependency inverts the flow of control by implementing an abstraction used by the sender.

High level policies are protected from low level details.