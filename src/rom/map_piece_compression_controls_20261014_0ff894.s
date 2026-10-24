.setcpu "65816"
.segment "CODE"
.org $F894
map_control_0ff894:
    .byte $E4 ; previous-row copy count
