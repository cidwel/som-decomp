.setcpu "65816"
.segment "CODE"
.org $7C99
map_control_0c7c99:
    .byte $E0 ; previous-row copy escape
    .byte $B0 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
