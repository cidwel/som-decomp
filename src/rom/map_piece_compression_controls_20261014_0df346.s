.setcpu "65816"
.segment "CODE"
.org $F346
map_control_0df346:
    .byte $C1 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
