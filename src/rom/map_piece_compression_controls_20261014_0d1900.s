.setcpu "65816"
.segment "CODE"
.org $1900
map_control_0d1900:
    .byte $E1 ; previous-row copy count
