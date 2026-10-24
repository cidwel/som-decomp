.setcpu "65816"
.segment "CODE"
.org $8FA2
map_control_0d8fa2:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
