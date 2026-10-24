.setcpu "65816"
.segment "CODE"
.org $68FA
map_control_0f68fa:
    .byte $E3 ; previous-row copy count
