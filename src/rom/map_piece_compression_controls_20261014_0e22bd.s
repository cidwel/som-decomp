.setcpu "65816"
.segment "CODE"
.org $22BD
map_control_0e22bd:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
