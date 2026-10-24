.setcpu "65816"
.segment "CODE"
.org $90CD
map_control_0c90cd:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
