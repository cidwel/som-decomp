.setcpu "65816"
.segment "CODE"
.org $DCBF
map_control_0ddcbf:
    .byte $E1 ; previous-row copy count
