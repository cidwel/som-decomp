.setcpu "65816"
.segment "CODE"
.org $F87D
map_control_0ff87d:
    .byte $E1 ; previous-row copy count
