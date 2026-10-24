.setcpu "65816"
.segment "CODE"
.org $FDCD
map_control_0dfdcd:
    .byte $E5 ; previous-row copy count
