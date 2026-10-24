.setcpu "65816"
.segment "CODE"
.org $46E1
map_control_0f46e1:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
