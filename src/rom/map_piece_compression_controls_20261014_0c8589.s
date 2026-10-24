.setcpu "65816"
.segment "CODE"
.org $8589
map_control_0c8589:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
