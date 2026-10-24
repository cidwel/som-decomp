.setcpu "65816"
.segment "CODE"
.org $4FE4
map_control_0d4fe4:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
