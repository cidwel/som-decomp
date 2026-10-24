.setcpu "65816"
.segment "CODE"
.org $5929
map_control_0f5929:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
