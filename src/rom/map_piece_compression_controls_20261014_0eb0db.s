.setcpu "65816"
.segment "CODE"
.org $B0DB
map_control_0eb0db:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
