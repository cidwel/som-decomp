.setcpu "65816"
.segment "CODE"
.org $DEDF
map_control_0fdedf:
    .byte $E2 ; previous-row copy count
