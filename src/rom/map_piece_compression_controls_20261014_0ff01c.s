.setcpu "65816"
.segment "CODE"
.org $F01C
map_control_0ff01c:
    .byte $E4 ; previous-row copy count
