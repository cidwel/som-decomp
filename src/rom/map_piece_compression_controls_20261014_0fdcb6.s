.setcpu "65816"
.segment "CODE"
.org $DCB6
map_control_0fdcb6:
    .byte $E1 ; previous-row copy count
    .byte $F1 ; progressive-copy count
