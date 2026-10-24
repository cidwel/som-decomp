.setcpu "65816"
.segment "CODE"
.org $CF24
map_control_0fcf24:
    .byte $E5 ; previous-row copy count
