.setcpu "65816"
.segment "CODE"
.org $163A
map_control_0e163a:
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
