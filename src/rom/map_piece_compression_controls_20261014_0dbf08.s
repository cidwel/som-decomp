.setcpu "65816"
.segment "CODE"
.org $BF08
map_control_0dbf08:
    .byte $E1 ; previous-row copy count
