.setcpu "65816"
.segment "CODE"
.org $E00C
map_control_0de00c:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
