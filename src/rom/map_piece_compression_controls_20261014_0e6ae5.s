.setcpu "65816"
.segment "CODE"
.org $6AE5
map_control_0e6ae5:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
