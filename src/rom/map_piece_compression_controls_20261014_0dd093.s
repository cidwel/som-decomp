.setcpu "65816"
.segment "CODE"
.org $D093
map_control_0dd093:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
