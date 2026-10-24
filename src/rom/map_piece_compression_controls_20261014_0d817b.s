.setcpu "65816"
.segment "CODE"
.org $817B
map_control_0d817b:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
