.setcpu "65816"
.segment "CODE"
.org $ACDE
map_control_0eacde:
    .byte $E1 ; previous-row copy count
