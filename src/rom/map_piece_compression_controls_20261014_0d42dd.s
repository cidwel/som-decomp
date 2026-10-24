.setcpu "65816"
.segment "CODE"
.org $42DD
map_control_0d42dd:
    .byte $E4 ; previous-row copy count
