.setcpu "65816"
.segment "CODE"
.org $F561
map_control_0ff561:
    .byte $E3 ; previous-row copy count
