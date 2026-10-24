.setcpu "65816"
.segment "CODE"
.org $8D00
map_control_0f8d00:
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
