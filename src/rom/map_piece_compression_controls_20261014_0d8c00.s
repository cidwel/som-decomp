.setcpu "65816"
.segment "CODE"
.org $8C00
map_control_0d8c00:
    .byte $E1 ; previous-row copy count
