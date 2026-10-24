.setcpu "65816"
.segment "CODE"
.org $E2D2
map_control_0fe2d2:
    .byte $D7 ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
