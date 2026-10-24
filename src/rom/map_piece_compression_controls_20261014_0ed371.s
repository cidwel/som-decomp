.setcpu "65816"
.segment "CODE"
.org $D371
map_control_0ed371:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
