.setcpu "65816"
.segment "CODE"
.org $BE01
map_control_0dbe01:
    .byte $E3 ; previous-row copy count
