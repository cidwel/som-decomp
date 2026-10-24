.setcpu "65816"
.segment "CODE"
.org $7707
map_control_0e7707:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
