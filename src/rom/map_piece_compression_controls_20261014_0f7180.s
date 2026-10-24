.setcpu "65816"
.segment "CODE"
.org $7180
map_control_0f7180:
    .byte $D5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
