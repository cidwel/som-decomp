.setcpu "65816"
.segment "CODE"
.org $F509
map_control_0ff509:
    .byte $E1 ; previous-row copy count
