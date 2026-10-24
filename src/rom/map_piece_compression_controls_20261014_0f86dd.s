.setcpu "65816"
.segment "CODE"
.org $86DD
map_control_0f86dd:
    .byte $E1 ; previous-row copy count
