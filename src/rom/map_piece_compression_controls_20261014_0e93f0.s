.setcpu "65816"
.segment "CODE"
.org $93F0
map_control_0e93f0:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
