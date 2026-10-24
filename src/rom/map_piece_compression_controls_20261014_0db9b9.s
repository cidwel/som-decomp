.setcpu "65816"
.segment "CODE"
.org $B9B9
map_control_0db9b9:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
