.setcpu "65816"
.segment "CODE"
.org $0954
map_control_0f0954:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
