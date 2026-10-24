.setcpu "65816"
.segment "CODE"
.org $8AB7
map_control_0d8ab7:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
