.setcpu "65816"
.segment "CODE"
.org $B503
map_control_0db503:
    .byte $E1 ; previous-row copy count
