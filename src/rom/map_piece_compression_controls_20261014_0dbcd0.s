.setcpu "65816"
.segment "CODE"
.org $BCD0
map_control_0dbcd0:
    .byte $E6 ; previous-row copy count
