.setcpu "65816"
.segment "CODE"
.org $6DDF
map_control_0c6ddf:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
