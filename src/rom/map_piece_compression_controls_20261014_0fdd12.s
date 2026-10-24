.setcpu "65816"
.segment "CODE"
.org $DD12
map_control_0fdd12:
    .byte $E3 ; previous-row copy count
