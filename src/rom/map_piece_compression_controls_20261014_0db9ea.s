.setcpu "65816"
.segment "CODE"
.org $B9EA
map_control_0db9ea:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
