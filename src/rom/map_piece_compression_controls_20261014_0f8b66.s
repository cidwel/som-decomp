.setcpu "65816"
.segment "CODE"
.org $8B66
map_control_0f8b66:
    .byte $C4 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $95 ; distance low bit/count
