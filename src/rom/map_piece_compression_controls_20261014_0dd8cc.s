.setcpu "65816"
.segment "CODE"
.org $D8CC
map_control_0dd8cc:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
