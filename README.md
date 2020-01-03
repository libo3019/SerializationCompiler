# SerializationCompiler
A serialization and deserialization compiler like protobuf and thrift.<br>
You can read the example files to learn how to use the serialization compiler.<br>
Usage：SerializationCompiler.exe -i &lt;filename&gt;<br>
It produces two files: .cc and .hh files.<br>

Features:<br>
Support int8, uint8, int16, uint16, int32, uint32, int64, uint64 types.<br>
Support float32, float64 types.<br>
Support bool type.<br>
Support string types.<br>
Support enum type.<br>
Support list, vector, set, map, stack, queue containers.<br>
Support the definition of optional field (in default case).<br>
Support the definition of required field.<br>
Support message like C/C++ struct.<br>
Support union like C/C++ union.<br>
Support repeated field like a vector.<br>
Support default value for integer, bool, string and enum type.<br>
Support nested definition: a message or union or enum can be defined in the another message, union.<br>
Support the high version of data where high version fields will be ignored when deserialization.
Support complex container type who contains any container like “queue&lt;list&lt;stack&lt;vector&lt;msg1&gt;&gt;&gt;&gt;”.<br>

You can use SerializationCompiler to process file formats and network protocols.