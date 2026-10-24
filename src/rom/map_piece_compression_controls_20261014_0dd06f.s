.setcpu "65816"
.segment "CODE"
.org $D06F
map_control_0dd06f:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
