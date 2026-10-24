.setcpu "65816"
.segment "CODE"
.org $0676
map_control_0f0676:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
