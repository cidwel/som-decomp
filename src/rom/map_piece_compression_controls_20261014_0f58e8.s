.setcpu "65816"
.segment "CODE"
.org $58E8
map_control_0f58e8:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
