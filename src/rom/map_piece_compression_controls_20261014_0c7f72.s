.setcpu "65816"
.segment "CODE"
.org $7F72
map_control_0c7f72:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
