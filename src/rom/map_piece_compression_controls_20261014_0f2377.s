.setcpu "65816"
.segment "CODE"
.org $2377
map_control_0f2377:
    .byte $EA ; backreference distance high bits
    .byte $89 ; distance low bit/count
