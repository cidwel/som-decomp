.setcpu "65816"
.segment "CODE"
.org $1F03
map_control_0d1f03:
    .byte $E3 ; previous-row copy count
