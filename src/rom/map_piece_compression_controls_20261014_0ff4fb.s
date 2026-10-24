.setcpu "65816"
.segment "CODE"
.org $F4FB
map_control_0ff4fb:
    .byte $E1 ; previous-row copy count
