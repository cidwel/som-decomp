.setcpu "65816"
.segment "CODE"
.org $F14A
map_control_0ff14a:
    .byte $E1 ; previous-row copy count
