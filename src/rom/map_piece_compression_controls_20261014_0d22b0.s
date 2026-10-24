.setcpu "65816"
.segment "CODE"
.org $22B0
map_control_0d22b0:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
