.setcpu "65816"
.segment "CODE"
.org $88AC
map_control_0f88ac:
    .byte $E1 ; previous-row copy count
