.setcpu "65816"
.segment "CODE"
.org $BFF8
map_control_0fbff8:
    .byte $E3 ; previous-row copy count
