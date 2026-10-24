.setcpu "65816"
.segment "CODE"
.org $AE4A
map_control_0eae4a:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $D5 ; same-value copy count/distance
