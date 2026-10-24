.setcpu "65816"
.segment "CODE"
.org $437C
map_control_0e437c:
    .byte $D1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
