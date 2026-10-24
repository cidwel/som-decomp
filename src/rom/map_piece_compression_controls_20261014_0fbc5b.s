.setcpu "65816"
.segment "CODE"
.org $BC5B
map_control_0fbc5b:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
