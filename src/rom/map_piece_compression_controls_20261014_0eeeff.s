.setcpu "65816"
.segment "CODE"
.org $EEFF
map_control_0eeeff:
    .byte $E7 ; previous-row copy count
