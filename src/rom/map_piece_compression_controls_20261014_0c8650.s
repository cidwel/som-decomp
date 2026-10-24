.setcpu "65816"
.segment "CODE"
.org $8650
map_control_0c8650:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
