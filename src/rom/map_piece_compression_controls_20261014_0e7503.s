.setcpu "65816"
.segment "CODE"
.org $7503
map_control_0e7503:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
