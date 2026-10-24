.setcpu "65816"
.segment "CODE"
.org $4304
map_control_0e4304:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
