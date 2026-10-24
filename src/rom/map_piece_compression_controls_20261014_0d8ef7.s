.setcpu "65816"
.segment "CODE"
.org $8EF7
map_control_0d8ef7:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
