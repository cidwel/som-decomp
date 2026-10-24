.setcpu "65816"
.segment "CODE"
.org $87E4
map_control_0c87e4:
    .byte $CA ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
