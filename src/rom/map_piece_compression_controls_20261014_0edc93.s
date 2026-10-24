.setcpu "65816"
.segment "CODE"
.org $DC93
map_control_0edc93:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
