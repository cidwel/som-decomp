.setcpu "65816"
.segment "CODE"
.org $4697
map_control_0d4697:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
