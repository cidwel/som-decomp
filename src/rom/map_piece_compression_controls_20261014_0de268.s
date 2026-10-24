.setcpu "65816"
.segment "CODE"
.org $E268
map_control_0de268:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
