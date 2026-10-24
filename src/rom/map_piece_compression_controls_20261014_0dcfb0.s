.setcpu "65816"
.segment "CODE"
.org $CFB0
map_control_0dcfb0:
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
