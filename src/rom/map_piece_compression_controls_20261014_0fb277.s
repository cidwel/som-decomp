.setcpu "65816"
.segment "CODE"
.org $B277
map_control_0fb277:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
