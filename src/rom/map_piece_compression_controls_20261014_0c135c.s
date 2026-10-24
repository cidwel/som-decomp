.setcpu "65816"
.segment "CODE"
.org $135C
map_control_0c135c:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $D9 ; same-value copy count/distance
