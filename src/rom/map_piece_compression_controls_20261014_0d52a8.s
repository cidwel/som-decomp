.setcpu "65816"
.segment "CODE"
.org $52A8
map_control_0d52a8:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
