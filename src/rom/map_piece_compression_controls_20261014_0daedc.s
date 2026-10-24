.setcpu "65816"
.segment "CODE"
.org $AEDC
map_control_0daedc:
    .byte $E1 ; previous-row copy count
