.setcpu "65816"
.segment "CODE"
.org $86AC
map_control_0f86ac:
    .byte $E5 ; previous-row copy count
