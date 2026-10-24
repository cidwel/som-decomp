.setcpu "65816"
.segment "CODE"
.org $FBBF
map_control_0dfbbf:
    .byte $E5 ; previous-row copy count
