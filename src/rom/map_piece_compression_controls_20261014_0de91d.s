.setcpu "65816"
.segment "CODE"
.org $E91D
map_control_0de91d:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
