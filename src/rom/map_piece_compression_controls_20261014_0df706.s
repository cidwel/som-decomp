.setcpu "65816"
.segment "CODE"
.org $F706
map_control_0df706:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
