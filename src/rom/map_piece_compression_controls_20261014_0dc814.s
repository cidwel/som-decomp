.setcpu "65816"
.segment "CODE"
.org $C814
map_control_0dc814:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
