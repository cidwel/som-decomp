.setcpu "65816"
.segment "CODE"
.org $B5F1
map_control_0eb5f1:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
