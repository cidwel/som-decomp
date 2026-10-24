.setcpu "65816"
.segment "CODE"
.org $0FF4
map_control_0e0ff4:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
