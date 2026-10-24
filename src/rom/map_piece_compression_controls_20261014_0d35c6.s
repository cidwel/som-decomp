.setcpu "65816"
.segment "CODE"
.org $35C6
map_control_0d35c6:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
