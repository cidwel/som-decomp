.setcpu "65816"
.segment "CODE"
.org $F90F
map_control_0ff90f:
    .byte $E2 ; previous-row copy count
