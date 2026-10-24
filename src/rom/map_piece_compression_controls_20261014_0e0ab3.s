.setcpu "65816"
.segment "CODE"
.org $0AB3
map_control_0e0ab3:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
