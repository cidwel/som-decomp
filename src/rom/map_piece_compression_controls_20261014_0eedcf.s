.setcpu "65816"
.segment "CODE"
.org $EDCF
map_control_0eedcf:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
