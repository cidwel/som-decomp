.setcpu "65816"
.segment "CODE"
.org $6211
map_control_0d6211:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
