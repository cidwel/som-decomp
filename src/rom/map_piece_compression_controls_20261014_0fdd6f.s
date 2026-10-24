.setcpu "65816"
.segment "CODE"
.org $DD6F
map_control_0fdd6f:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
