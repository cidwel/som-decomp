.setcpu "65816"
.segment "CODE"
.org $D110
map_control_0dd110:
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
