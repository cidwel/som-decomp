.setcpu "65816"
.segment "CODE"
.org $AA64
map_control_0faa64:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
