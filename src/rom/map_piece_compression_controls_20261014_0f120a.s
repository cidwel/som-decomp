.setcpu "65816"
.segment "CODE"
.org $120A
map_control_0f120a:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $D2 ; same-value copy count/distance
