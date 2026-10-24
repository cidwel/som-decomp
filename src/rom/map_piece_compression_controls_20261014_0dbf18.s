.setcpu "65816"
.segment "CODE"
.org $BF18
map_control_0dbf18:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
