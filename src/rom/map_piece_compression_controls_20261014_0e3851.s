.setcpu "65816"
.segment "CODE"
.org $3851
map_control_0e3851:
    .byte $C1 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
