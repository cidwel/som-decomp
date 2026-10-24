.setcpu "65816"
.segment "CODE"
.org $CA82
map_control_0dca82:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
