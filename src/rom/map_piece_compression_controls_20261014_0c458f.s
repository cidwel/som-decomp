.setcpu "65816"
.segment "CODE"
.org $458F
map_control_0c458f:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
