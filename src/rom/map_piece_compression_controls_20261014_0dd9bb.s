.setcpu "65816"
.segment "CODE"
.org $D9BB
map_control_0dd9bb:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
