.setcpu "65816"
.segment "CODE"
.org $CE3F
map_control_0dce3f:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
