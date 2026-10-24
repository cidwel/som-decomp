.setcpu "65816"
.segment "CODE"
.org $C48C
map_control_0ec48c:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
