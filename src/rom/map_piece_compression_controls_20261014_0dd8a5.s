.setcpu "65816"
.segment "CODE"
.org $D8A5
map_control_0dd8a5:
    .byte $E0 ; previous-row copy escape
    .byte $A3 ; row-distance/count
