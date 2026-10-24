.setcpu "65816"
.segment "CODE"
.org $A7A9
map_control_0ea7a9:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
