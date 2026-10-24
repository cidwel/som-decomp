.setcpu "65816"
.segment "CODE"
.org $CDBD
map_control_0dcdbd:
    .byte $E5 ; previous-row copy count
