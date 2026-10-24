.setcpu "65816"
.segment "CODE"
.org $B5A0
map_control_0fb5a0:
    .byte $E0 ; previous-row copy escape
    .byte $B3 ; row-distance/count
