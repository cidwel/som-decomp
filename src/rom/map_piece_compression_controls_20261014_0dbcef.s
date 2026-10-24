.setcpu "65816"
.segment "CODE"
.org $BCEF
map_control_0dbcef:
    .byte $E6 ; previous-row copy count
