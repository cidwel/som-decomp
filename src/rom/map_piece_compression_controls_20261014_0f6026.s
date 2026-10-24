.setcpu "65816"
.segment "CODE"
.org $6026
map_control_0f6026:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
