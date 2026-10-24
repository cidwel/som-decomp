.setcpu "65816"
.segment "CODE"
.org $CA35
map_control_0dca35:
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
