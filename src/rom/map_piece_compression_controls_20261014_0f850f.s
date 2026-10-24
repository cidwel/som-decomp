.setcpu "65816"
.segment "CODE"
.org $850F
map_control_0f850f:
    .byte $E6 ; previous-row copy count
