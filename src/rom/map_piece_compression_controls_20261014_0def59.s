.setcpu "65816"
.segment "CODE"
.org $EF59
map_control_0def59:
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
