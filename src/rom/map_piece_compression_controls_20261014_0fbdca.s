.setcpu "65816"
.segment "CODE"
.org $BDCA
map_control_0fbdca:
    .byte $E3 ; previous-row copy count
