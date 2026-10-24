.setcpu "65816"
.segment "CODE"
.org $40A7
map_control_0e40a7:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
