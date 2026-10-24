.setcpu "65816"
.segment "CODE"
.org $7DBC
map_control_0d7dbc:
    .byte $C5 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
