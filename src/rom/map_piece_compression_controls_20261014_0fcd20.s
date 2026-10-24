.setcpu "65816"
.segment "CODE"
.org $CD20
map_control_0fcd20:
    .byte $E1 ; previous-row copy count
