.setcpu "65816"
.segment "CODE"
.org $149C
map_control_0c149c:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
