.setcpu "65816"
.segment "CODE"
.org $9076
map_control_0e9076:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
