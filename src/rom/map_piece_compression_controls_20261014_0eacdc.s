.setcpu "65816"
.segment "CODE"
.org $ACDC
map_control_0eacdc:
    .byte $E4 ; previous-row copy count
