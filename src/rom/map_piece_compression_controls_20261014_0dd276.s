.setcpu "65816"
.segment "CODE"
.org $D276
map_control_0dd276:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
