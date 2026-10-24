.setcpu "65816"
.segment "CODE"
.org $B28E
map_control_0fb28e:
    .byte $C2 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
