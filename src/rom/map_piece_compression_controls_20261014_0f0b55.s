.setcpu "65816"
.segment "CODE"
.org $0B55
map_control_0f0b55:
    .byte $E7 ; previous-row copy count
