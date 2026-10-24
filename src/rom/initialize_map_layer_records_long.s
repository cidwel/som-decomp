; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_map_layer_records = $A6C9

.segment "CODE"
.org $A6C5
initialize_map_layer_records_long:
    jsr initialize_map_layer_records
    rtl
