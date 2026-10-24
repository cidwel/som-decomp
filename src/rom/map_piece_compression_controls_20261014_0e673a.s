.setcpu "65816"
.segment "CODE"
.org $673A
map_control_0e673a:
    .byte $E8 ; backreference distance high bits
    .byte $3A ; distance low bit/count
