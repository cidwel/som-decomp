.setcpu "65816"
.segment "CODE"
.org $D23C
map_control_0dd23c:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
