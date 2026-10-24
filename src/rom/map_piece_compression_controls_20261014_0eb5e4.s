.setcpu "65816"
.segment "CODE"
.org $B5E4
map_control_0eb5e4:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
