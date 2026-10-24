.setcpu "65816"
.segment "CODE"
.org $EBED
map_control_0debed:
    .byte $E1 ; previous-row copy count
