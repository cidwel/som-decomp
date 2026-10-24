.setcpu "65816"
.segment "CODE"
.org $C846
map_control_0dc846:
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
