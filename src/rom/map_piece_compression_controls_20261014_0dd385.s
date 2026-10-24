.setcpu "65816"
.segment "CODE"
.org $D385
map_control_0dd385:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
