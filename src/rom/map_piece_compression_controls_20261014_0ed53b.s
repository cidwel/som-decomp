.setcpu "65816"
.segment "CODE"
.org $D53B
map_control_0ed53b:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
