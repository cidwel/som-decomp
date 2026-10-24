.setcpu "65816"
.segment "CODE"
.org $23B7
map_control_0c23b7:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
