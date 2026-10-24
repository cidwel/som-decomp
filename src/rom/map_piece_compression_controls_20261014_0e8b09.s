.setcpu "65816"
.segment "CODE"
.org $8B09
map_control_0e8b09:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
