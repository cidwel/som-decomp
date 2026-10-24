.setcpu "65816"
.segment "CODE"
.org $9DA7
map_control_0f9da7:
    .byte $D2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
