.setcpu "65816"
.segment "CODE"
.org $0020
map_control_0f0020:
    .byte $E5 ; previous-row copy count
