.setcpu "65816"
.segment "CODE"
.org $E8B2
map_control_0de8b2:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
