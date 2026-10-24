.setcpu "65816"
.segment "CODE"
.org $DA2B
map_control_0fda2b:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
