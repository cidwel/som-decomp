.setcpu "65816"
.segment "CODE"
.org $767A
map_control_0d767a:
    .byte $E0 ; previous-row copy escape
    .byte $AB ; row-distance/count
