.setcpu "65816"
.segment "CODE"
.org $8A6B
map_control_0d8a6b:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
