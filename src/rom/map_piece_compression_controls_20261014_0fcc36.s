.setcpu "65816"
.segment "CODE"
.org $CC36
map_control_0fcc36:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
