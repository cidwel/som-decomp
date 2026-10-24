.setcpu "65816"
.segment "CODE"
.org $CC04
map_control_0fcc04:
    .byte $C2 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
