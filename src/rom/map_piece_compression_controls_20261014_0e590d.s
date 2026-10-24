.setcpu "65816"
.segment "CODE"
.org $590D
map_control_0e590d:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
