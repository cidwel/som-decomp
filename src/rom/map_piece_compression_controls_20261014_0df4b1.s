.setcpu "65816"
.segment "CODE"
.org $F4B1
map_control_0df4b1:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
