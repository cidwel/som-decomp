.setcpu "65816"
.segment "CODE"
.org $F49B
map_control_0ff49b:
    .byte $E1 ; previous-row copy count
