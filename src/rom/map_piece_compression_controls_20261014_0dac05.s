.setcpu "65816"
.segment "CODE"
.org $AC05
map_control_0dac05:
    .byte $E4 ; previous-row copy count
