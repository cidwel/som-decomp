.setcpu "65816"
.segment "CODE"
.org $6C29
map_control_0d6c29:
    .byte $C4 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
