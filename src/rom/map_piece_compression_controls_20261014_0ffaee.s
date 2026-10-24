.setcpu "65816"
.segment "CODE"
.org $FAEE
map_control_0ffaee:
    .byte $E1 ; previous-row copy count
