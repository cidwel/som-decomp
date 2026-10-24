.setcpu "65816"
.segment "CODE"
.org $CD6E
map_control_0fcd6e:
    .byte $E5 ; previous-row copy count
