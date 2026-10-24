.setcpu "65816"
.segment "CODE"
.org $6264
map_control_0d6264:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
