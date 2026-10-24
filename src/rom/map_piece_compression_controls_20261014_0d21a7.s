.setcpu "65816"
.segment "CODE"
.org $21A7
map_control_0d21a7:
    .byte $E0 ; previous-row copy escape
    .byte $9E ; row-distance/count
    .byte $C2 ; same-value copy count/distance
