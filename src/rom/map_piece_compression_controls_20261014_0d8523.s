.setcpu "65816"
.segment "CODE"
.org $8523
map_control_0d8523:
    .byte $E0 ; previous-row copy escape
    .byte $55 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
