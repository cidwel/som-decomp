.setcpu "65816"
.segment "CODE"
.org $15AC
map_control_0f15ac:
    .byte $E1 ; previous-row copy count
