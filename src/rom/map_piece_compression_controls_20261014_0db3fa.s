.setcpu "65816"
.segment "CODE"
.org $B3FA
map_control_0db3fa:
    .byte $E2 ; previous-row copy count
