.setcpu "65816"
.segment "CODE"
.org $EEBF
map_control_0deebf:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
