.setcpu "65816"
.segment "CODE"
.org $B4EA
map_control_0db4ea:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
