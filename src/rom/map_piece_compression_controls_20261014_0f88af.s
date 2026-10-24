.setcpu "65816"
.segment "CODE"
.org $88AF
map_control_0f88af:
    .byte $E3 ; previous-row copy count
