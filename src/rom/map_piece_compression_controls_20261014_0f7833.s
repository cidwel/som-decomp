.setcpu "65816"
.segment "CODE"
.org $7833
map_control_0f7833:
    .byte $E8 ; backreference distance high bits
    .byte $2A ; distance low bit/count
