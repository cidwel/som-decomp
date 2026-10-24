.setcpu "65816"
.segment "CODE"
.org $70BE
map_control_0f70be:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
