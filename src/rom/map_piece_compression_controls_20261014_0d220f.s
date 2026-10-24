.setcpu "65816"
.segment "CODE"
.org $220F
map_control_0d220f:
    .byte $E6 ; previous-row copy count
