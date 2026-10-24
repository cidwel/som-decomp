.setcpu "65816"
.segment "CODE"
.org $7C46
map_control_0f7c46:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
