.setcpu "65816"
.segment "CODE"
.org $88A8
map_control_0f88a8:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
