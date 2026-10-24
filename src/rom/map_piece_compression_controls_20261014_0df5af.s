.setcpu "65816"
.segment "CODE"
.org $F5AF
map_control_0df5af:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
