.setcpu "65816"
.segment "CODE"
.org $1FC0
map_control_0d1fc0:
    .byte $E1 ; previous-row copy count
