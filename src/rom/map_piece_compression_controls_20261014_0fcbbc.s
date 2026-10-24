.setcpu "65816"
.segment "CODE"
.org $CBBC
map_control_0fcbbc:
    .byte $E1 ; previous-row copy count
