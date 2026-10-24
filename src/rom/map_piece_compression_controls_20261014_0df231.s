.setcpu "65816"
.segment "CODE"
.org $F231
map_control_0df231:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
