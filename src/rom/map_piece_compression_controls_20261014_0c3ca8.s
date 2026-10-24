.setcpu "65816"
.segment "CODE"
.org $3CA8
map_control_0c3ca8:
    .byte $E0 ; previous-row copy escape
    .byte $98 ; row-distance/count
