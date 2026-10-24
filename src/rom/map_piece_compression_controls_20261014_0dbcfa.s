.setcpu "65816"
.segment "CODE"
.org $BCFA
map_control_0dbcfa:
    .byte $E3 ; previous-row copy count
