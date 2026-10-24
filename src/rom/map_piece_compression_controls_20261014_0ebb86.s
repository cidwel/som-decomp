.setcpu "65816"
.segment "CODE"
.org $BB86
map_control_0ebb86:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
