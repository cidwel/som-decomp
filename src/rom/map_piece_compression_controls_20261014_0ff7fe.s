.setcpu "65816"
.segment "CODE"
.org $F7FE
map_control_0ff7fe:
    .byte $E2 ; previous-row copy count
