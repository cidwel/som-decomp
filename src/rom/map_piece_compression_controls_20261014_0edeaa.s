.setcpu "65816"
.segment "CODE"
.org $DEAA
map_control_0edeaa:
    .byte $E2 ; previous-row copy count
