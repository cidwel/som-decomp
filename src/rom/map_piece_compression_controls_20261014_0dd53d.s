.setcpu "65816"
.segment "CODE"
.org $D53D
map_control_0dd53d:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
