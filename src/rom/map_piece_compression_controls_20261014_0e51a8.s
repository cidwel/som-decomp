.setcpu "65816"
.segment "CODE"
.org $51A8
map_control_0e51a8:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
