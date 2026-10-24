.setcpu "65816"
.segment "CODE"
.org $80D6
map_control_0d80d6:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
