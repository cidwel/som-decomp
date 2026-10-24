.setcpu "65816"
.segment "CODE"
.org $01FD
map_control_0e01fd:
    .byte $E7 ; previous-row copy count
