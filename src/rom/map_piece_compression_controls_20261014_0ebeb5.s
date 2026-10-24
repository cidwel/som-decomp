.setcpu "65816"
.segment "CODE"
.org $BEB5
map_control_0ebeb5:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
