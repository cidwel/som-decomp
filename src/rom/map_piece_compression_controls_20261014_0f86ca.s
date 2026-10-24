.setcpu "65816"
.segment "CODE"
.org $86CA
map_control_0f86ca:
    .byte $E7 ; previous-row copy count
