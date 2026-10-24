.setcpu "65816"
.segment "CODE"
.org $D390
map_control_0ed390:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
