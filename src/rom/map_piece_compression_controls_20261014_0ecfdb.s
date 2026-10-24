.setcpu "65816"
.segment "CODE"
.org $CFDB
map_control_0ecfdb:
    .byte $E3 ; previous-row copy count
