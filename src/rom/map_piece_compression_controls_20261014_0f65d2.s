.setcpu "65816"
.segment "CODE"
.org $65D2
map_control_0f65d2:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
