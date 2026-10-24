.setcpu "65816"
.segment "CODE"
.org $D8BD
map_control_0dd8bd:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
