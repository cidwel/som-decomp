.setcpu "65816"
.segment "CODE"
.org $3DD5
map_control_0f3dd5:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
