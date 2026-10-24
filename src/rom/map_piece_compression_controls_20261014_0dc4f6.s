.setcpu "65816"
.segment "CODE"
.org $C4F6
map_control_0dc4f6:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
