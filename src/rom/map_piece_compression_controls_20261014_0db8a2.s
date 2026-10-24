.setcpu "65816"
.segment "CODE"
.org $B8A2
map_control_0db8a2:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
