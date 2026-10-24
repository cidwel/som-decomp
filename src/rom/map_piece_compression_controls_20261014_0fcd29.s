.setcpu "65816"
.segment "CODE"
.org $CD29
map_control_0fcd29:
    .byte $E2 ; previous-row copy count
