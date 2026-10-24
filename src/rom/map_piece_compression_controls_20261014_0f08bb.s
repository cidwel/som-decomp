.setcpu "65816"
.segment "CODE"
.org $08BB
map_control_0f08bb:
    .byte $E6 ; previous-row copy count
