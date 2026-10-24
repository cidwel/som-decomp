.setcpu "65816"
.segment "CODE"
.org $73FD
map_control_0f73fd:
    .byte $E3 ; previous-row copy count
