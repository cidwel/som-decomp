.setcpu "65816"
.segment "CODE"
.org $560B
map_control_0d560b:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
