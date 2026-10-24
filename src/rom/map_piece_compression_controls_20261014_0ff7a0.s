.setcpu "65816"
.segment "CODE"
.org $F7A0
map_control_0ff7a0:
    .byte $E6 ; previous-row copy count
