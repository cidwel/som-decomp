.setcpu "65816"
.segment "CODE"
.org $CD68
map_control_0fcd68:
    .byte $E5 ; previous-row copy count
