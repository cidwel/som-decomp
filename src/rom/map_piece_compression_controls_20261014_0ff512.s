.setcpu "65816"
.segment "CODE"
.org $F512
map_control_0ff512:
    .byte $E3 ; previous-row copy count
