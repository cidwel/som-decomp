.setcpu "65816"
.segment "CODE"
.org $7D0D
map_control_0d7d0d:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $63 ; row-distance/count
