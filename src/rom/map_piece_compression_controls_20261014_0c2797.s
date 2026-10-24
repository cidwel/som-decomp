.setcpu "65816"
.segment "CODE"
.org $2797
map_control_0c2797:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
