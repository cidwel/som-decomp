.setcpu "65816"
.segment "CODE"
.org $0FAD
map_control_0f0fad:
    .byte $E3 ; previous-row copy count
