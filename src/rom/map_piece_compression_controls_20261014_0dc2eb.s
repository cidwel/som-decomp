.setcpu "65816"
.segment "CODE"
.org $C2EB
map_control_0dc2eb:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
