.setcpu "65816"
.segment "CODE"
.org $23C9
map_control_0c23c9:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
