.setcpu "65816"
.segment "CODE"
.org $F7FB
map_control_0ff7fb:
    .byte $E2 ; previous-row copy count
