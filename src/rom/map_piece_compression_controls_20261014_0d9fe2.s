.setcpu "65816"
.segment "CODE"
.org $9FE2
map_control_0d9fe2:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
