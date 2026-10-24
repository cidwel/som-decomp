.setcpu "65816"
.segment "CODE"
.org $8808
map_control_0c8808:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
