.setcpu "65816"
.segment "CODE"
.org $2AAC
map_control_0e2aac:
    .byte $E0 ; previous-row copy escape
    .byte $7B ; row-distance/count
