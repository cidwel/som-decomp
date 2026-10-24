.setcpu "65816"
.segment "CODE"
.org $1F1B
map_control_0f1f1b:
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $D7 ; same-value copy count/distance
