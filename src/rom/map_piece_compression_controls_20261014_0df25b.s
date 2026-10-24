.setcpu "65816"
.segment "CODE"
.org $F25B
map_control_0df25b:
    .byte $E0 ; previous-row copy escape
    .byte $98 ; row-distance/count
