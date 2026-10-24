.setcpu "65816"
.segment "CODE"
.org $C91A
map_control_0dc91a:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
