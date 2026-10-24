.setcpu "65816"
.segment "CODE"
.org $6C56
map_control_0c6c56:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
