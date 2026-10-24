.setcpu "65816"
.segment "CODE"
.org $D9A9
map_control_0dd9a9:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
