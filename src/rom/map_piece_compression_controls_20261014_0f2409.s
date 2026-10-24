.setcpu "65816"
.segment "CODE"
.org $2409
map_control_0f2409:
    .byte $E1 ; previous-row copy count
    .byte $D7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
