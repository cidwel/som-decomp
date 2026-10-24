.setcpu "65816"
.segment "CODE"
.org $5246
map_control_0d5246:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
