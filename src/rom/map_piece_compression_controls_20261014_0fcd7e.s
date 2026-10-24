.setcpu "65816"
.segment "CODE"
.org $CD7E
map_control_0fcd7e:
    .byte $E5 ; previous-row copy count
