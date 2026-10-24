.setcpu "65816"
.segment "CODE"
.org $B520
map_control_0db520:
    .byte $E2 ; previous-row copy count
