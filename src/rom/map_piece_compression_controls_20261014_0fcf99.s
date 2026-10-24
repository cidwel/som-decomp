.setcpu "65816"
.segment "CODE"
.org $CF99
map_control_0fcf99:
    .byte $E4 ; previous-row copy count
