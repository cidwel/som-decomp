.setcpu "65816"
.segment "CODE"
.org $F6CD
map_control_0ff6cd:
    .byte $E6 ; previous-row copy count
