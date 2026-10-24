.setcpu "65816"
.segment "CODE"
.org $EEED
map_control_0eeeed:
    .byte $E7 ; previous-row copy count
