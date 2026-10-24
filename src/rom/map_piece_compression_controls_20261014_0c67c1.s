.setcpu "65816"
.segment "CODE"
.org $67C1
map_control_0c67c1:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
