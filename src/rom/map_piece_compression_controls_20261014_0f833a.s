.setcpu "65816"
.segment "CODE"
.org $833A
map_control_0f833a:
    .byte $DF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
