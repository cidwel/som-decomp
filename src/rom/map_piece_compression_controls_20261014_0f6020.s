.setcpu "65816"
.segment "CODE"
.org $6020
map_control_0f6020:
    .byte $CC ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $07 ; distance low bit/count
