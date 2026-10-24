.setcpu "65816"
.segment "CODE"
.org $2D66
map_control_0d2d66:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
