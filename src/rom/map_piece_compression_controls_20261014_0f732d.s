.setcpu "65816"
.segment "CODE"
.org $732D
map_control_0f732d:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
