.setcpu "65816"
.segment "CODE"
.org $885D
map_control_0d885d:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
