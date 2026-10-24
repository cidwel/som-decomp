.setcpu "65816"
.segment "CODE"
.org $7267
map_control_0c7267:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
