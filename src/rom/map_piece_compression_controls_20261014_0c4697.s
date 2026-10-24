.setcpu "65816"
.segment "CODE"
.org $4697
map_control_0c4697:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
