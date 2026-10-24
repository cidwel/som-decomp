.setcpu "65816"
.segment "CODE"
.org $F922
map_control_0ff922:
    .byte $E2 ; previous-row copy count
