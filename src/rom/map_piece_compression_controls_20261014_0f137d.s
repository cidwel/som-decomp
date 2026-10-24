.setcpu "65816"
.segment "CODE"
.org $137D
map_control_0f137d:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
