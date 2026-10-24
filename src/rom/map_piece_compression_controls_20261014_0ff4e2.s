.setcpu "65816"
.segment "CODE"
.org $F4E2
map_control_0ff4e2:
    .byte $E4 ; previous-row copy count
