.setcpu "65816"
.segment "CODE"
.org $F1CD
map_control_0ff1cd:
    .byte $E1 ; previous-row copy count
