.setcpu "65816"
.segment "CODE"
.org $7A82
map_control_0d7a82:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
