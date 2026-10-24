.setcpu "65816"
.segment "CODE"
.org $AEC8
map_control_0faec8:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
