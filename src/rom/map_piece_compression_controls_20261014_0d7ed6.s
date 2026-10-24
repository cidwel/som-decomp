.setcpu "65816"
.segment "CODE"
.org $7ED6
map_control_0d7ed6:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
