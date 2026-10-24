.setcpu "65816"
.segment "CODE"
.org $CFFB
map_control_0ecffb:
    .byte $E3 ; previous-row copy count
