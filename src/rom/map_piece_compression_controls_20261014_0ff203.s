.setcpu "65816"
.segment "CODE"
.org $F203
map_control_0ff203:
    .byte $E1 ; previous-row copy count
