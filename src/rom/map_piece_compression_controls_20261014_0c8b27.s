.setcpu "65816"
.segment "CODE"
.org $8B27
map_control_0c8b27:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
