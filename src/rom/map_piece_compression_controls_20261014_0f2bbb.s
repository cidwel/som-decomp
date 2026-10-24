.setcpu "65816"
.segment "CODE"
.org $2BBB
map_control_0f2bbb:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $C7 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
