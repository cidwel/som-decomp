.setcpu "65816"
.segment "CODE"
.org $F518
map_control_0ff518:
    .byte $E1 ; previous-row copy count
