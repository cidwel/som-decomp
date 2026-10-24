.setcpu "65816"
.segment "CODE"
.org $23D4
map_control_0e23d4:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
