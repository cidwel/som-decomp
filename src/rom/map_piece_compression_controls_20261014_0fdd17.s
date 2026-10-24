.setcpu "65816"
.segment "CODE"
.org $DD17
map_control_0fdd17:
    .byte $E1 ; previous-row copy count
