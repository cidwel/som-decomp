.setcpu "65816"
.segment "CODE"
.org $8357
map_control_0d8357:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
