.setcpu "65816"
.segment "CODE"
.org $2197
map_control_0f2197:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
