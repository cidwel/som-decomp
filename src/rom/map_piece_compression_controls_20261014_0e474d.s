.setcpu "65816"
.segment "CODE"
.org $474D
map_control_0e474d:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
