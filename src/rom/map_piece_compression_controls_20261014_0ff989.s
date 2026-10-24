.setcpu "65816"
.segment "CODE"
.org $F989
map_control_0ff989:
    .byte $E6 ; previous-row copy count
