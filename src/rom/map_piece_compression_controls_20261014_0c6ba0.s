.setcpu "65816"
.segment "CODE"
.org $6BA0
map_control_0c6ba0:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
