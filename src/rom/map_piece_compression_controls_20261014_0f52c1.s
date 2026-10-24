.setcpu "65816"
.segment "CODE"
.org $52C1
map_control_0f52c1:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
