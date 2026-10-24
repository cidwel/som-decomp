.setcpu "65816"
.segment "CODE"
.org $D319
map_control_0dd319:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
