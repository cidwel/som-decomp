.setcpu "65816"
.segment "CODE"
.org $3111
map_control_0f3111:
    .byte $E0 ; previous-row copy escape
    .byte $AC ; row-distance/count
