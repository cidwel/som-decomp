.setcpu "65816"
.segment "CODE"
.org $8AB1
map_control_0d8ab1:
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count
