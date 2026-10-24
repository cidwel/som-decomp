.setcpu "65816"
.segment "CODE"
.org $D0D9
map_control_0fd0d9:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
