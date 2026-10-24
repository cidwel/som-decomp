.setcpu "65816"
.segment "CODE"
.org $52EC
map_control_0d52ec:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
