.setcpu "65816"
.segment "CODE"
.org $F006
map_control_0ff006:
    .byte $E1 ; previous-row copy count
