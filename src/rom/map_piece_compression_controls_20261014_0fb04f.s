.setcpu "65816"
.segment "CODE"
.org $B04F
map_control_0fb04f:
    .byte $E6 ; previous-row copy count
