.setcpu "65816"
.segment "CODE"
.org $2020
map_control_0f2020:
    .byte $E5 ; previous-row copy count
