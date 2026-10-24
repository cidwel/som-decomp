.setcpu "65816"
.segment "CODE"
.org $4AA5
map_control_0e4aa5:
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
