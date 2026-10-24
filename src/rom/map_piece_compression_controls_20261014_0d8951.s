.setcpu "65816"
.segment "CODE"
.org $8951
map_control_0d8951:
    .byte $E6 ; previous-row copy count
    .byte $CA ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
