.setcpu "65816"
.segment "CODE"
.org $4BAE
map_control_0e4bae:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
