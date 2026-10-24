.setcpu "65816"
.segment "CODE"
.org $CEDB
map_control_0fcedb:
    .byte $E3 ; previous-row copy count
