.setcpu "65816"
.segment "CODE"
.org $F21F
map_control_0ef21f:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $F1 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
