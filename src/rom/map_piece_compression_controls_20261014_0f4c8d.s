.setcpu "65816"
.segment "CODE"
.org $4C8D
map_control_0f4c8d:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
