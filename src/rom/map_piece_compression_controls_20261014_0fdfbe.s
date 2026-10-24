.setcpu "65816"
.segment "CODE"
.org $DFBE
map_control_0fdfbe:
    .byte $E3 ; previous-row copy count
