.setcpu "65816"
.segment "CODE"
.org $AC94
map_control_0dac94:
    .byte $E6 ; previous-row copy count
