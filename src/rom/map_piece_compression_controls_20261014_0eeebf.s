.setcpu "65816"
.segment "CODE"
.org $EEBF
map_control_0eeebf:
    .byte $E7 ; previous-row copy count
