.setcpu "65816"
.segment "CODE"
.org $DAC2
map_control_0fdac2:
    .byte $E3 ; previous-row copy count
