.setcpu "65816"
.segment "CODE"
.org $0BEB
map_control_0f0beb:
    .byte $E0 ; previous-row copy escape
    .byte $B1 ; row-distance/count
