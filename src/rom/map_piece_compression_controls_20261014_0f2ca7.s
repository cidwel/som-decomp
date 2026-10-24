.setcpu "65816"
.segment "CODE"
.org $2CA7
map_control_0f2ca7:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
