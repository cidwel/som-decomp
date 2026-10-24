.setcpu "65816"
.segment "CODE"
.org $2F02
map_control_0f2f02:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
