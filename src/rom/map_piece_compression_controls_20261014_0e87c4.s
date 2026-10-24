.setcpu "65816"
.segment "CODE"
.org $87C4
map_control_0e87c4:
    .byte $C3 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
