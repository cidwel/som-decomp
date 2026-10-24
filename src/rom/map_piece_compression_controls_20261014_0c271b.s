.setcpu "65816"
.segment "CODE"
.org $271B
map_control_0c271b:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
