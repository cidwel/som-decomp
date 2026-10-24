.setcpu "65816"
.segment "CODE"
.org $D34D
map_control_0dd34d:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
