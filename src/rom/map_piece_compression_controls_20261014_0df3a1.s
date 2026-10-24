.setcpu "65816"
.segment "CODE"
.org $F3A1
map_control_0df3a1:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
