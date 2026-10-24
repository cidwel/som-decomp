.setcpu "65816"
.segment "CODE"
.org $F8ED
map_control_0ff8ed:
    .byte $E2 ; previous-row copy count
