.setcpu "65816"
.segment "CODE"
.org $E63B
map_control_0de63b:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
