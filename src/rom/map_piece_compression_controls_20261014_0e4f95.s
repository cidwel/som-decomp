.setcpu "65816"
.segment "CODE"
.org $4F95
map_control_0e4f95:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
