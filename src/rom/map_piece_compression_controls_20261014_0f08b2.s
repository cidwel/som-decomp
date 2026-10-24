.setcpu "65816"
.segment "CODE"
.org $08B2
map_control_0f08b2:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
