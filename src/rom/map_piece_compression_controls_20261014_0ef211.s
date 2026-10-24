.setcpu "65816"
.segment "CODE"
.org $F211
map_control_0ef211:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
