.setcpu "65816"
.segment "CODE"
.org $6512
map_control_0d6512:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
