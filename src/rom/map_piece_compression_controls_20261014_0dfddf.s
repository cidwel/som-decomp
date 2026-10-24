.setcpu "65816"
.segment "CODE"
.org $FDDF
map_control_0dfddf:
    .byte $E5 ; previous-row copy count
