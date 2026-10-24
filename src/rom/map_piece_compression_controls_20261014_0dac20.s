.setcpu "65816"
.segment "CODE"
.org $AC20
map_control_0dac20:
    .byte $E7 ; previous-row copy count
