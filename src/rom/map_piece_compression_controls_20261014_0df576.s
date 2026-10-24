.setcpu "65816"
.segment "CODE"
.org $F576
map_control_0df576:
    .byte $E5 ; previous-row copy count
