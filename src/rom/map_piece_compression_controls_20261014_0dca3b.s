.setcpu "65816"
.segment "CODE"
.org $CA3B
map_control_0dca3b:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
