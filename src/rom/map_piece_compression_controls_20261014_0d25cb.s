.setcpu "65816"
.segment "CODE"
.org $25CB
map_control_0d25cb:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
