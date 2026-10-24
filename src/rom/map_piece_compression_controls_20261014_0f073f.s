.setcpu "65816"
.segment "CODE"
.org $073F
map_control_0f073f:
    .byte $E6 ; previous-row copy count
