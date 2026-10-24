.setcpu "65816"
.segment "CODE"
.org $0102
map_control_0f0102:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
