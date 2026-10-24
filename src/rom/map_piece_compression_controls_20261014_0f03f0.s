.setcpu "65816"
.segment "CODE"
.org $03F0
map_control_0f03f0:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
