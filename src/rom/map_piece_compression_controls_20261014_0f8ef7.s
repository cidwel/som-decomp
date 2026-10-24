.setcpu "65816"
.segment "CODE"
.org $8EF7
map_control_0f8ef7:
    .byte $E9 ; backreference distance high bits
    .byte $1F ; distance low bit/count
