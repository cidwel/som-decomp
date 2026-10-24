.setcpu "65816"
.segment "CODE"
.org $F162
map_control_0cf162:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
