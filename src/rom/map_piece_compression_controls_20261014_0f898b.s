.setcpu "65816"
.segment "CODE"
.org $898B
map_control_0f898b:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
