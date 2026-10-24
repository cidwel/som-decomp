.setcpu "65816"
.segment "CODE"
.org $DD06
map_control_0fdd06:
    .byte $E7 ; previous-row copy count
