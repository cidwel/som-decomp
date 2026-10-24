.setcpu "65816"
.segment "CODE"
.org $4952
map_control_0f4952:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
