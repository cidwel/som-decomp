.setcpu "65816"
.segment "CODE"
.org $0ABA
map_control_0e0aba:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
