.setcpu "65816"
.segment "CODE"
.org $37BD
map_control_0f37bd:
    .byte $E3 ; previous-row copy count
