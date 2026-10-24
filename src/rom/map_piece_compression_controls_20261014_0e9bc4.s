.setcpu "65816"
.segment "CODE"
.org $9BC4
map_control_0e9bc4:
    .byte $D1 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
