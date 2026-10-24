.setcpu "65816"
.segment "CODE"
.org $0E10
map_control_0f0e10:
    .byte $E6 ; previous-row copy count
