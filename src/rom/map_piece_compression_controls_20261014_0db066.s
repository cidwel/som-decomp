.setcpu "65816"
.segment "CODE"
.org $B066
map_control_0db066:
    .byte $E3 ; previous-row copy count
