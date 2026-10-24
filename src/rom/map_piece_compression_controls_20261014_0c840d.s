.setcpu "65816"
.segment "CODE"
.org $840D
map_control_0c840d:
    .byte $F1 ; progressive-copy count
    .byte $E6 ; previous-row copy count
