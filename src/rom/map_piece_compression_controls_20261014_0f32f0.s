.setcpu "65816"
.segment "CODE"
.org $32F0
map_control_0f32f0:
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
