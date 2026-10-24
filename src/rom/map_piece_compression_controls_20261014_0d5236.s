.setcpu "65816"
.segment "CODE"
.org $5236
map_control_0d5236:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
