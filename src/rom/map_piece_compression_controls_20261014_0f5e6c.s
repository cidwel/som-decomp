.setcpu "65816"
.segment "CODE"
.org $5E6C
map_control_0f5e6c:
    .byte $E3 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
