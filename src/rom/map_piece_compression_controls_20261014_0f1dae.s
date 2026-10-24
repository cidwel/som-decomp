.setcpu "65816"
.segment "CODE"
.org $1DAE
map_control_0f1dae:
    .byte $E2 ; previous-row copy count
