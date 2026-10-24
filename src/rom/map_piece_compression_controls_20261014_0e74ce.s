.setcpu "65816"
.segment "CODE"
.org $74CE
map_control_0e74ce:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
