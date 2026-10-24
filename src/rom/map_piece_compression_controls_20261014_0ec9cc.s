.setcpu "65816"
.segment "CODE"
.org $C9CC
map_control_0ec9cc:
    .byte $F1 ; progressive-copy count
    .byte $E6 ; previous-row copy count
