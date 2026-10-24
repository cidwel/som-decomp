.setcpu "65816"
.segment "CODE"
.org $54EE
map_control_0f54ee:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
