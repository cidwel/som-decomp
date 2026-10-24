.setcpu "65816"
.segment "CODE"
.org $117F
map_control_0f117f:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
