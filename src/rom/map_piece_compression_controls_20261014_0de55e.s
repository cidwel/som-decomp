.setcpu "65816"
.segment "CODE"
.org $E55E
map_control_0de55e:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
