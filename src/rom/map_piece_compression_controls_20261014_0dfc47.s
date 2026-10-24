.setcpu "65816"
.segment "CODE"
.org $FC47
map_control_0dfc47:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
