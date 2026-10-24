.setcpu "65816"
.segment "CODE"
.org $EC03
map_control_0eec03:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
