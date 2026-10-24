.setcpu "65816"
.segment "CODE"
.org $0AD4
map_control_0d0ad4:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
