.setcpu "65816"
.segment "CODE"
.org $BF89
map_control_0dbf89:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
