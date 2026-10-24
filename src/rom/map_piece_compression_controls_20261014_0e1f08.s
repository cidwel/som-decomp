.setcpu "65816"
.segment "CODE"
.org $1F08
map_control_0e1f08:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
