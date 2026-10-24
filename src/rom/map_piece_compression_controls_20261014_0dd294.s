.setcpu "65816"
.segment "CODE"
.org $D294
map_control_0dd294:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
