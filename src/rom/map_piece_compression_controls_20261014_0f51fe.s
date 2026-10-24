.setcpu "65816"
.segment "CODE"
.org $51FE
map_control_0f51fe:
    .byte $E5 ; previous-row copy count
