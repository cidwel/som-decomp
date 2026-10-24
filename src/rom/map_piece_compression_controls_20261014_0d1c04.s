.setcpu "65816"
.segment "CODE"
.org $1C04
map_control_0d1c04:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
