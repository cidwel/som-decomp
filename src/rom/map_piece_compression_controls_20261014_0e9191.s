.setcpu "65816"
.segment "CODE"
.org $9191
map_control_0e9191:
    .byte $E8 ; backreference distance high bits
    .byte $6F ; distance low bit/count
