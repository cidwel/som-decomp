.setcpu "65816"
.segment "CODE"
.org $6364
map_control_0d6364:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
