.setcpu "65816"
.segment "CODE"
.org $21EA
map_control_0e21ea:
    .byte $D7 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
