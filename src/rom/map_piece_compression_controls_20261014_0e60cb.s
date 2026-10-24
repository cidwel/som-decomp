.setcpu "65816"
.segment "CODE"
.org $60CB
map_control_0e60cb:
    .byte $E3 ; previous-row copy count
