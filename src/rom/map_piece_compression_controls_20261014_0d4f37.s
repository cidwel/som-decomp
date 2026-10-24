.setcpu "65816"
.segment "CODE"
.org $4F37
map_control_0d4f37:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
