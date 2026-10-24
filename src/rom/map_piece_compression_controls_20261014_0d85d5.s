.setcpu "65816"
.segment "CODE"
.org $85D5
map_control_0d85d5:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
