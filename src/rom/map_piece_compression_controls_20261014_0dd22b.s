.setcpu "65816"
.segment "CODE"
.org $D22B
map_control_0dd22b:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
