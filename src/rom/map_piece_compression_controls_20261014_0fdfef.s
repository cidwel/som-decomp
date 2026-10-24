.setcpu "65816"
.segment "CODE"
.org $DFEF
map_control_0fdfef:
    .byte $E6 ; previous-row copy count
