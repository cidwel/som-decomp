.setcpu "65816"
.segment "CODE"
.org $5C37
map_control_0d5c37:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
