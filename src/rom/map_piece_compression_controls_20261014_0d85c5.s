.setcpu "65816"
.segment "CODE"
.org $85C5
map_control_0d85c5:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
