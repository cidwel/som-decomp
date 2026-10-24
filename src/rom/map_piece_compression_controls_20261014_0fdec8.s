.setcpu "65816"
.segment "CODE"
.org $DEC8
map_control_0fdec8:
    .byte $E5 ; previous-row copy count
