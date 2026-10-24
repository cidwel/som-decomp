.setcpu "65816"
.segment "CODE"
.org $1312
map_control_0f1312:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
