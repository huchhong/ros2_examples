# subsribe the same topic multiple times with different callback on the same node

This usage shows that you can subscribe the same topic multipic times with 
different callback. In this way, each callback would be invoked when the topic
is received.

This feature does surprise me at first. I found this usage in the implementation
of DynamicParamsClient which registers different callbacks on 'parameter_event' 
in differnent part within one node.
