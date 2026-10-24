.setcpu "65816"
.segment "CODE"
.org $B98A
map_control_0db98a:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
