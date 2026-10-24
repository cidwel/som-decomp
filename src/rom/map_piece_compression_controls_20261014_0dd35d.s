.setcpu "65816"
.segment "CODE"
.org $D35D
map_control_0dd35d:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
