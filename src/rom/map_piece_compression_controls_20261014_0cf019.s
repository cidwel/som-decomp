.setcpu "65816"
.segment "CODE"
.org $F019
map_control_0cf019:
    .byte $E6 ; previous-row copy count
