.setcpu "65816"
.segment "CODE"
.org $D8D5
map_control_0dd8d5:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
