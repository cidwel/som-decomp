.setcpu "65816"
.segment "CODE"
.org $F88C
map_control_0ff88c:
    .byte $E1 ; previous-row copy count
