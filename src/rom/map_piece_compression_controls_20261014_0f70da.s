.setcpu "65816"
.segment "CODE"
.org $70DA
map_control_0f70da:
    .byte $E3 ; previous-row copy count
