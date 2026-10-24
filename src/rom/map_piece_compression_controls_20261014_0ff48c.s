.setcpu "65816"
.segment "CODE"
.org $F48C
map_control_0ff48c:
    .byte $E1 ; previous-row copy count
