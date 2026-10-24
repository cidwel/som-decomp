.setcpu "65816"
.segment "CODE"
.org $85C9
map_control_0c85c9:
    .byte $E2 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count
