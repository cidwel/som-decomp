.setcpu "65816"
.segment "CODE"
.org $ECA1
map_control_0feca1:
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $90 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
