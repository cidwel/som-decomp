.setcpu "65816"
.segment "CODE"
.org $59B0
map_control_0d59b0:
    .byte $E8 ; backreference distance high bits
    .byte $60 ; distance low bit/count
