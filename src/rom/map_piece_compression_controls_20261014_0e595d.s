.setcpu "65816"
.segment "CODE"
.org $595D
map_control_0e595d:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
