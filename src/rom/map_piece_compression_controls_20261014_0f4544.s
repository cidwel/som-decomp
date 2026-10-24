.setcpu "65816"
.segment "CODE"
.org $4544
map_control_0f4544:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
    .byte $E4 ; previous-row copy count
