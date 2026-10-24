.setcpu "65816"
.segment "CODE"
.org $6E98
map_control_0c6e98:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C3 ; same-value copy count/distance
