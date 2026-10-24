.setcpu "65816"
.segment "CODE"
.org $D569
map_control_0fd569:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
