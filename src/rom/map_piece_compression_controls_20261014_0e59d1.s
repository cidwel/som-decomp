.setcpu "65816"
.segment "CODE"
.org $59D1
map_control_0e59d1:
    .byte $E0 ; previous-row copy escape
    .byte $A6 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
