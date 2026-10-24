.setcpu "65816"
.segment "CODE"
.org $559B
map_control_0f559b:
    .byte $F1 ; progressive-copy count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
