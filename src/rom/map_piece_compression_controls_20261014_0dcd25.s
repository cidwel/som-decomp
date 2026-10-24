.setcpu "65816"
.segment "CODE"
.org $CD25
map_control_0dcd25:
    .byte $E6 ; previous-row copy count
