.setcpu "65816"
.segment "CODE"
.org $B919
map_control_0db919:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
