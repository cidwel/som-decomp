.setcpu "65816"
.segment "CODE"
.org $F7D2
map_control_0ff7d2:
    .byte $E6 ; previous-row copy count
