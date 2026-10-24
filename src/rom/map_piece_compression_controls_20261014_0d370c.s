.setcpu "65816"
.segment "CODE"
.org $370C
map_control_0d370c:
    .byte $CA ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
