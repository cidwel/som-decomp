.setcpu "65816"
.segment "CODE"
.org $7775
map_control_0d7775:
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
