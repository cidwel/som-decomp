.setcpu "65816"
.segment "CODE"
.org $EEC9
map_control_0deec9:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
