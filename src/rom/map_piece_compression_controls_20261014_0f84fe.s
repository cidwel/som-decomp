.setcpu "65816"
.segment "CODE"
.org $84FE
map_control_0f84fe:
    .byte $E3 ; previous-row copy count
