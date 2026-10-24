.setcpu "65816"
.segment "CODE"
.org $56EE
map_control_0d56ee:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
