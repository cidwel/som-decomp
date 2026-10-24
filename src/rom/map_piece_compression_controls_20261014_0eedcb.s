.setcpu "65816"
.segment "CODE"
.org $EDCB
map_control_0eedcb:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
