.setcpu "65816"
.segment "CODE"
.org $D721
map_control_0fd721:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
