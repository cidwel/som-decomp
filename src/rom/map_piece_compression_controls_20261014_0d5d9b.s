.setcpu "65816"
.segment "CODE"
.org $5D9B
map_control_0d5d9b:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
