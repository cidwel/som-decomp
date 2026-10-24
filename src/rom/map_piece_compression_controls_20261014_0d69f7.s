.setcpu "65816"
.segment "CODE"
.org $69F7
map_control_0d69f7:
    .byte $E3 ; previous-row copy count
    .byte $F1 ; progressive-copy count
