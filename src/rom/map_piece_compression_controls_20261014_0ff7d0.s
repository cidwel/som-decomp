.setcpu "65816"
.segment "CODE"
.org $F7D0
map_control_0ff7d0:
    .byte $E2 ; previous-row copy count
