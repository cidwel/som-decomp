.setcpu "65816"
.segment "CODE"
.org $F86B
map_control_0ff86b:
    .byte $E1 ; previous-row copy count
