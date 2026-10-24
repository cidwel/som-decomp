.setcpu "65816"
.segment "CODE"
.org $232F
map_control_0f232f:
    .byte $E3 ; previous-row copy count
