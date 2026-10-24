.setcpu "65816"
.segment "CODE"
.org $F977
map_control_0df977:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
