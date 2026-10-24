.setcpu "65816"
.segment "CODE"
.org $FCFD
map_control_0efcfd:
    .byte $D7 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $93 ; distance low bit/count
