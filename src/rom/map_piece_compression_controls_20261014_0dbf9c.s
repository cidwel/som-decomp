.setcpu "65816"
.segment "CODE"
.org $BF9C
map_control_0dbf9c:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
