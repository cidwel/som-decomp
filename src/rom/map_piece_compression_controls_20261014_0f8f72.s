.setcpu "65816"
.segment "CODE"
.org $8F72
map_control_0f8f72:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
