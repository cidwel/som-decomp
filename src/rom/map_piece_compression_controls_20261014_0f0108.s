.setcpu "65816"
.segment "CODE"
.org $0108
map_control_0f0108:
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count
