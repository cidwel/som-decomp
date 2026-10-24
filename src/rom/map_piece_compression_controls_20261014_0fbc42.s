.setcpu "65816"
.segment "CODE"
.org $BC42
map_control_0fbc42:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
