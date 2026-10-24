.setcpu "65816"
.segment "CODE"
.org $746A
map_control_0c746a:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
