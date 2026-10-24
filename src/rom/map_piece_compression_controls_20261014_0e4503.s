.setcpu "65816"
.segment "CODE"
.org $4503
map_control_0e4503:
    .byte $F1 ; progressive-copy count
    .byte $E5 ; previous-row copy count
