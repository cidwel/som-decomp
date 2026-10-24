.setcpu "65816"
.segment "CODE"
.org $241F
map_control_0c241f:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
