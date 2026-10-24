.setcpu "65816"
.segment "CODE"
.org $0537
map_control_0f0537:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
