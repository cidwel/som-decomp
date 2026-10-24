.setcpu "65816"
.segment "CODE"
.org $B29B
map_control_0fb29b:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
