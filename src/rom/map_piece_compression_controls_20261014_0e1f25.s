.setcpu "65816"
.segment "CODE"
.org $1F25
map_control_0e1f25:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
