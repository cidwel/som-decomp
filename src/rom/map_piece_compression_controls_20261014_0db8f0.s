.setcpu "65816"
.segment "CODE"
.org $B8F0
map_control_0db8f0:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
