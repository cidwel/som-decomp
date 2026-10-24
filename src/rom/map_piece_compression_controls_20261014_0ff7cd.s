.setcpu "65816"
.segment "CODE"
.org $F7CD
map_control_0ff7cd:
    .byte $E2 ; previous-row copy count
