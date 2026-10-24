.setcpu "65816"
.segment "CODE"
.org $CD99
map_control_0dcd99:
    .byte $E1 ; previous-row copy count
