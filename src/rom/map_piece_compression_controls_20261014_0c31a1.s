.setcpu "65816"
.segment "CODE"
.org $31A1
map_control_0c31a1:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
