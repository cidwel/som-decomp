.setcpu "65816"
.segment "CODE"
.org $05DE
map_control_0f05de:
    .byte $E1 ; previous-row copy count
