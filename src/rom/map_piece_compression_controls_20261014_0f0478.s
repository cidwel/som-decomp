.setcpu "65816"
.segment "CODE"
.org $0478
map_control_0f0478:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
