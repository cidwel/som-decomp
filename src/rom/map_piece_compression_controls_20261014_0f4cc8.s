.setcpu "65816"
.segment "CODE"
.org $4CC8
map_control_0f4cc8:
    .byte $E0 ; previous-row copy escape
    .byte $60 ; row-distance/count
