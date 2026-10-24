.setcpu "65816"
.segment "CODE"
.org $293E
map_control_0c293e:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
