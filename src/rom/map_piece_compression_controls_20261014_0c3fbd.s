.setcpu "65816"
.segment "CODE"
.org $3FBD
map_control_0c3fbd:
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
