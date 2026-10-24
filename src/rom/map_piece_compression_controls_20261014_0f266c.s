.setcpu "65816"
.segment "CODE"
.org $266C
map_control_0f266c:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
