.setcpu "65816"
.segment "CODE"
.org $DC85
map_control_0ddc85:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
