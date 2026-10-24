.setcpu "65816"
.segment "CODE"
.org $F84E
map_control_0ff84e:
    .byte $E2 ; previous-row copy count
