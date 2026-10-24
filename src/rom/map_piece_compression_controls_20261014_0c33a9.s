.setcpu "65816"
.segment "CODE"
.org $33A9
map_control_0c33a9:
    .byte $DF ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $38 ; distance low bit/count
