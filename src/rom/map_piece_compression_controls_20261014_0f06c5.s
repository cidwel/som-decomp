.setcpu "65816"
.segment "CODE"
.org $06C5
map_control_0f06c5:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
