.setcpu "65816"
.segment "CODE"
.org $8F25
map_control_0f8f25:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
