.setcpu "65816"
.segment "CODE"
.org $86A2
map_control_0c86a2:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
