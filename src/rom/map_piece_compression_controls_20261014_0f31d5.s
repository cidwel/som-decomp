.setcpu "65816"
.segment "CODE"
.org $31D5
map_control_0f31d5:
    .byte $CB ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $A7 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
