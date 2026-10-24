.setcpu "65816"
.segment "CODE"
.org $6A70
map_control_0d6a70:
    .byte $E1 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
