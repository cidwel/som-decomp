.setcpu "65816"
.segment "CODE"
.org $FA52
map_control_0efa52:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
