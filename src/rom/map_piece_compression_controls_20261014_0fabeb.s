.setcpu "65816"
.segment "CODE"
.org $ABEB
map_control_0fabeb:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
