.setcpu "65816"
.segment "CODE"
.org $D18D
map_control_0dd18d:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
