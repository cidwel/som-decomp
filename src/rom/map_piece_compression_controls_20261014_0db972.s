.setcpu "65816"
.segment "CODE"
.org $B972
map_control_0db972:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
