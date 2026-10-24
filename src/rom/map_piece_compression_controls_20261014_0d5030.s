.setcpu "65816"
.segment "CODE"
.org $5030
map_control_0d5030:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
