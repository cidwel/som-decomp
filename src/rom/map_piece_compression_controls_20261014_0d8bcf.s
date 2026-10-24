.setcpu "65816"
.segment "CODE"
.org $8BCF
map_control_0d8bcf:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
