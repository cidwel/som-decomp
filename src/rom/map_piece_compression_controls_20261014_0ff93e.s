.setcpu "65816"
.segment "CODE"
.org $F93E
map_control_0ff93e:
    .byte $E2 ; previous-row copy count
