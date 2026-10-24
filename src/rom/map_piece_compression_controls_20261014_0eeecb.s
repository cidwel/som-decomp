.setcpu "65816"
.segment "CODE"
.org $EECB
map_control_0eeecb:
    .byte $E5 ; previous-row copy count
