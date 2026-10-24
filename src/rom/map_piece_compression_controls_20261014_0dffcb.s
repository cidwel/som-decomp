.setcpu "65816"
.segment "CODE"
.org $FFCB
map_control_0dffcb:
    .byte $E3 ; previous-row copy count
