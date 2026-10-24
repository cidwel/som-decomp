.setcpu "65816"
.segment "CODE"
.org $BAA6
map_control_0fbaa6:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
