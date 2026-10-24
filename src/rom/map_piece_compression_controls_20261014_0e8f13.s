.setcpu "65816"
.segment "CODE"
.org $8F13
map_control_0e8f13:
    .byte $C9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
