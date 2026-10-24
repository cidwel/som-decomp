.setcpu "65816"
.segment "CODE"
.org $8331
map_control_0f8331:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
