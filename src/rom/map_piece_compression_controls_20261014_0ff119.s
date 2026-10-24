.setcpu "65816"
.segment "CODE"
.org $F119
map_control_0ff119:
    .byte $E2 ; previous-row copy count
