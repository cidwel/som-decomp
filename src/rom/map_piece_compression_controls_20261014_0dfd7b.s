.setcpu "65816"
.segment "CODE"
.org $FD7B
map_control_0dfd7b:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
