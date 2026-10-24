.setcpu "65816"
.segment "CODE"
.org $5A69
map_control_0e5a69:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
