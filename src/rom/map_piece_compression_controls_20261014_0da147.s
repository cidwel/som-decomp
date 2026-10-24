.setcpu "65816"
.segment "CODE"
.org $A147
map_control_0da147:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
