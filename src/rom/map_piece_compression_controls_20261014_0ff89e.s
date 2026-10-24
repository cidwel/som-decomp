.setcpu "65816"
.segment "CODE"
.org $F89E
map_control_0ff89e:
    .byte $E2 ; previous-row copy count
