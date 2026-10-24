.setcpu "65816"
.segment "CODE"
.org $CFBD
map_control_0dcfbd:
    .byte $E2 ; previous-row copy count
