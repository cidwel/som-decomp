.setcpu "65816"
.segment "CODE"
.org $F112
map_control_0df112:
    .byte $E1 ; previous-row copy count
