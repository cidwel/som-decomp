.setcpu "65816"
.segment "CODE"
.org $E2AE
map_control_0fe2ae:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
