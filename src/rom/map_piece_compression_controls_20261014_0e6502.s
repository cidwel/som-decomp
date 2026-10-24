.setcpu "65816"
.segment "CODE"
.org $6502
map_control_0e6502:
    .byte $E1 ; previous-row copy count
