.setcpu "65816"
.segment "CODE"
.org $09CE
map_control_0e09ce:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
