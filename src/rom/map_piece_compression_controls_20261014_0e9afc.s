.setcpu "65816"
.segment "CODE"
.org $9AFC
map_control_0e9afc:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
