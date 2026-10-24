.setcpu "65816"
.segment "CODE"
.org $17FE
map_control_0f17fe:
    .byte $E4 ; previous-row copy count
