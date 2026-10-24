.setcpu "65816"
.segment "CODE"
.org $0E01
map_control_0f0e01:
    .byte $E6 ; previous-row copy count
