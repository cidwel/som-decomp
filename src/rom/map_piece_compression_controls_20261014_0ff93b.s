.setcpu "65816"
.segment "CODE"
.org $F93B
map_control_0ff93b:
    .byte $E2 ; previous-row copy count
