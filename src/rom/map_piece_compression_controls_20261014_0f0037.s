.setcpu "65816"
.segment "CODE"
.org $0037
map_control_0f0037:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
