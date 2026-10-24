.setcpu "65816"
.segment "CODE"
.org $AC07
map_control_0dac07:
    .byte $E2 ; previous-row copy count
