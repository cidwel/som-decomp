.setcpu "65816"
.segment "CODE"
.org $811C
map_control_0f811c:
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
