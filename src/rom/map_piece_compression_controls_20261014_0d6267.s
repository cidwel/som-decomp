.setcpu "65816"
.segment "CODE"
.org $6267
map_control_0d6267:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
