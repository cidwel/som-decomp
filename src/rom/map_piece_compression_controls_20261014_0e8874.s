.setcpu "65816"
.segment "CODE"
.org $8874
map_control_0e8874:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
