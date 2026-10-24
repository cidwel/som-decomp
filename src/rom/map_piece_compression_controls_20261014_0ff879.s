.setcpu "65816"
.segment "CODE"
.org $F879
map_control_0ff879:
    .byte $E2 ; previous-row copy count
