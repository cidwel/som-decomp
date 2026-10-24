.setcpu "65816"
.segment "CODE"
.org $F81B
map_control_0ff81b:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
