.setcpu "65816"
.segment "CODE"
.org $EC0E
map_control_0fec0e:
    .byte $E1 ; previous-row copy count
