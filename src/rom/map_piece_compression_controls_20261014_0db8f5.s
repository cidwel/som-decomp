.setcpu "65816"
.segment "CODE"
.org $B8F5
map_control_0db8f5:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
