.setcpu "65816"
.segment "CODE"
.org $82EC
map_control_0e82ec:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
