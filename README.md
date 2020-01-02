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
Support list, vector, set, map containers.<br>
Support the definition of optional field (in default case).<br>
Support the definition of required field.<br>
Support message like C/C++ struct.<br>
Support union like C/C++ union.<br>
Support repeat field like a vector.<br>
Support the default value for integer, bool, string and enum type.<br>