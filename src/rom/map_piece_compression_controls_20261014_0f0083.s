.setcpu "65816"
.segment "CODE"
.org $0083
map_control_0f0083:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
