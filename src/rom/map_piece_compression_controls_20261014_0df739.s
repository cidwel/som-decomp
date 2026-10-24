.setcpu "65816"
.segment "CODE"
.org $F739
map_control_0df739:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
