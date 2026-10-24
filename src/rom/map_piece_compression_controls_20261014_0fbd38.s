.setcpu "65816"
.segment "CODE"
.org $BD38
map_control_0fbd38:
    .byte $E1 ; previous-row copy count
