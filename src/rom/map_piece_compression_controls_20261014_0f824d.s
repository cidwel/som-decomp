.setcpu "65816"
.segment "CODE"
.org $824D
map_control_0f824d:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $CA ; same-value copy count/distance
