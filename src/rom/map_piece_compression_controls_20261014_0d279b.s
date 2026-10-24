.setcpu "65816"
.segment "CODE"
.org $279B
map_control_0d279b:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
