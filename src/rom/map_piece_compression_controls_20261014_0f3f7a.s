.setcpu "65816"
.segment "CODE"
.org $3F7A
map_control_0f3f7a:
    .byte $E0 ; previous-row copy escape
    .byte $4B ; row-distance/count
