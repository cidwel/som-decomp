.setcpu "65816"
.segment "CODE"
.org $3391
map_control_0e3391:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
