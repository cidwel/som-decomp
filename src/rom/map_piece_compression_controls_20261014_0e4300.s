.setcpu "65816"
.segment "CODE"
.org $4300
map_control_0e4300:
    .byte $E6 ; previous-row copy count
