.setcpu "65816"
.segment "CODE"
.org $F52B
map_control_0ff52b:
    .byte $E1 ; previous-row copy count
