.setcpu "65816"
.segment "CODE"
.org $090B
map_control_0f090b:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
