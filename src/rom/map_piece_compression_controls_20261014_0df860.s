.setcpu "65816"
.segment "CODE"
.org $F860
map_control_0df860:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
