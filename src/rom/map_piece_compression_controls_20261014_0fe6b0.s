.setcpu "65816"
.segment "CODE"
.org $E6B0
map_control_0fe6b0:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
