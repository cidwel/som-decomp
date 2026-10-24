.setcpu "65816"
.segment "CODE"
.org $0C21
map_control_0e0c21:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
