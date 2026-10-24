.setcpu "65816"
.segment "CODE"
.org $8D79
map_control_0d8d79:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
    .byte $C4 ; same-value copy count/distance
