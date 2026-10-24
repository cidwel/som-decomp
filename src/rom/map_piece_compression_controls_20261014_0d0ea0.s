.setcpu "65816"
.segment "CODE"
.org $0EA0
map_control_0d0ea0:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
