.setcpu "65816"
.segment "CODE"
.org $E648
map_control_0de648:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
