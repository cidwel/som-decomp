.setcpu "65816"
.segment "CODE"
.org $DFFF
map_control_0fdfff:
    .byte $E6 ; previous-row copy count
