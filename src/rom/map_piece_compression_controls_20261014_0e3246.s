.setcpu "65816"
.segment "CODE"
.org $3246
map_control_0e3246:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
