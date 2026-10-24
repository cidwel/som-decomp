.setcpu "65816"
.segment "CODE"
.org $F9EA
map_control_0df9ea:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
