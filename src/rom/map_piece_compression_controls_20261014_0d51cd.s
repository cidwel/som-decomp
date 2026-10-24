.setcpu "65816"
.segment "CODE"
.org $51CD
map_control_0d51cd:
    .byte $E1 ; previous-row copy count
