.setcpu "65816"
.segment "CODE"
.org $7BF3
map_control_0f7bf3:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
