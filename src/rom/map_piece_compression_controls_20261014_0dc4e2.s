.setcpu "65816"
.segment "CODE"
.org $C4E2
map_control_0dc4e2:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
