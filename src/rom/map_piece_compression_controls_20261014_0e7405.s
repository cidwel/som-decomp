.setcpu "65816"
.segment "CODE"
.org $7405
map_control_0e7405:
    .byte $E0 ; previous-row copy escape
    .byte $98 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
