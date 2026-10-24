.setcpu "65816"
.segment "CODE"
.org $AC32
map_control_0dac32:
    .byte $E3 ; previous-row copy count
