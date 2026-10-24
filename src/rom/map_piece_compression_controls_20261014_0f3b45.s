.setcpu "65816"
.segment "CODE"
.org $3B45
map_control_0f3b45:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
