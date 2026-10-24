.setcpu "65816"
.segment "CODE"
.org $F1DC
map_control_0ff1dc:
    .byte $E1 ; previous-row copy count
