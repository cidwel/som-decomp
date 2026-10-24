.setcpu "65816"
.segment "CODE"
.org $341A
map_control_0c341a:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
