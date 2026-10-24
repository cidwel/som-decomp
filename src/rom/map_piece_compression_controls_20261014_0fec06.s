.setcpu "65816"
.segment "CODE"
.org $EC06
map_control_0fec06:
    .byte $E1 ; previous-row copy count
