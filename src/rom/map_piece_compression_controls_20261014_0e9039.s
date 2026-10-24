.setcpu "65816"
.segment "CODE"
.org $9039
map_control_0e9039:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
