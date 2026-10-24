.setcpu "65816"
.segment "CODE"
.org $F236
map_control_0df236:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
