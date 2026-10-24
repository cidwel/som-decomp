.setcpu "65816"
.segment "CODE"
.org $96F9
map_control_0e96f9:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
