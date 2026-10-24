.setcpu "65816"
.segment "CODE"
.org $6D2F
map_control_0c6d2f:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
