.setcpu "65816"
.segment "CODE"
.org $2295
map_control_0f2295:
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
