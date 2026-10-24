.setcpu "65816"
.segment "CODE"
.org $1D2F
map_control_0d1d2f:
    .byte $E0 ; previous-row copy escape
    .byte $AF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C1 ; same-value copy count/distance
