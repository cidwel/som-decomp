.setcpu "65816"
.segment "CODE"
.org $52A1
map_control_0e52a1:
    .byte $E0 ; previous-row copy escape
    .byte $AB ; row-distance/count
