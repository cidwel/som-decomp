.setcpu "65816"
.segment "CODE"
.org $B8E5
map_control_0db8e5:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
