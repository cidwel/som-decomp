.setcpu "65816"
.segment "CODE"
.org $26DB
map_control_0d26db:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
