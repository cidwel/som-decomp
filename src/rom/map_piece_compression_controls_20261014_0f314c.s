.setcpu "65816"
.segment "CODE"
.org $314C
map_control_0f314c:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
