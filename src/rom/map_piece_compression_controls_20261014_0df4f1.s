.setcpu "65816"
.segment "CODE"
.org $F4F1
map_control_0df4f1:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
