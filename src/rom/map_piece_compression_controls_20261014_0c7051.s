.setcpu "65816"
.segment "CODE"
.org $7051
map_control_0c7051:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $E5 ; previous-row copy count
