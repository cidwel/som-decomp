.setcpu "65816"
.segment "CODE"
.org $5E82
map_control_0f5e82:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
