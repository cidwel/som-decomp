.setcpu "65816"
.segment "CODE"
.org $8BA8
map_control_0c8ba8:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
