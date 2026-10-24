.setcpu "65816"
.segment "CODE"
.org $8781
map_control_0c8781:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
