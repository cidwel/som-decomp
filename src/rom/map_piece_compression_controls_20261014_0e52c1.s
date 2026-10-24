.setcpu "65816"
.segment "CODE"
.org $52C1
map_control_0e52c1:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
