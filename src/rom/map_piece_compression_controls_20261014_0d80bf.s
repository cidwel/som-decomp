.setcpu "65816"
.segment "CODE"
.org $80BF
map_control_0d80bf:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
