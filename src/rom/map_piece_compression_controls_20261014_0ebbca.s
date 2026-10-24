.setcpu "65816"
.segment "CODE"
.org $BBCA
map_control_0ebbca:
    .byte $E6 ; previous-row copy count
