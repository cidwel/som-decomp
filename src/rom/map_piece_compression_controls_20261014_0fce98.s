.setcpu "65816"
.segment "CODE"
.org $CE98
map_control_0fce98:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
