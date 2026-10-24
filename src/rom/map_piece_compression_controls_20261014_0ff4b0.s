.setcpu "65816"
.segment "CODE"
.org $F4B0
map_control_0ff4b0:
    .byte $E1 ; previous-row copy count
