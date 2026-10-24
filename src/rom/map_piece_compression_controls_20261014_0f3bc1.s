.setcpu "65816"
.segment "CODE"
.org $3BC1
map_control_0f3bc1:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
