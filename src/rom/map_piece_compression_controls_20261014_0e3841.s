.setcpu "65816"
.segment "CODE"
.org $3841
map_control_0e3841:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
