.setcpu "65816"
.segment "CODE"
.org $883B
map_control_0d883b:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
