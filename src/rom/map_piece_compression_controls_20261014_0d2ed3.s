.setcpu "65816"
.segment "CODE"
.org $2ED3
map_control_0d2ed3:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
