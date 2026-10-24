.setcpu "65816"
.segment "CODE"
.org $BBDE
map_control_0ebbde:
    .byte $E1 ; previous-row copy count
