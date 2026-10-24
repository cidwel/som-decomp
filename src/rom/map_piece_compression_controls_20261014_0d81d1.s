.setcpu "65816"
.segment "CODE"
.org $81D1
map_control_0d81d1:
    .byte $E0 ; previous-row copy escape
    .byte $40 ; row-distance/count
