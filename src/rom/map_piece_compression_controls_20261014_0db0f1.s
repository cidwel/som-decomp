.setcpu "65816"
.segment "CODE"
.org $B0F1
map_control_0db0f1:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
