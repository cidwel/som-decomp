.setcpu "65816"
.segment "CODE"
.org $CDCD
map_control_0dcdcd:
    .byte $E2 ; previous-row copy count
