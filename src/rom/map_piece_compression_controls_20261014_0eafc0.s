.setcpu "65816"
.segment "CODE"
.org $AFC0
map_control_0eafc0:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
