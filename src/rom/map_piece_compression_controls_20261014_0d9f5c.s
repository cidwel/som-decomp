.setcpu "65816"
.segment "CODE"
.org $9F5C
map_control_0d9f5c:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
