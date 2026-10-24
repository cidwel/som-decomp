.setcpu "65816"
.segment "CODE"
.org $5C16
map_control_0e5c16:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
