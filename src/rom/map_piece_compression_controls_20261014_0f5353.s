.setcpu "65816"
.segment "CODE"
.org $5353
map_control_0f5353:
    .byte $C2 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
