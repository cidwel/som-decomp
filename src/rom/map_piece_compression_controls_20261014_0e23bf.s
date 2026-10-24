.setcpu "65816"
.segment "CODE"
.org $23BF
map_control_0e23bf:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
