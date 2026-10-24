.setcpu "65816"
.segment "CODE"
.org $170F
map_control_0e170f:
    .byte $E1 ; previous-row copy count
