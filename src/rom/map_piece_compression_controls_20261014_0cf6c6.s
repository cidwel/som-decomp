.setcpu "65816"
.segment "CODE"
.org $F6C6
map_control_0cf6c6:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
