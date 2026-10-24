.setcpu "65816"
.segment "CODE"
.org $FFBE
map_control_0dffbe:
    .byte $E1 ; previous-row copy count
