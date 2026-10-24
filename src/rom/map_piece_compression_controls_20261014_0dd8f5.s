.setcpu "65816"
.segment "CODE"
.org $D8F5
map_control_0dd8f5:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
