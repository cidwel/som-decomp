.setcpu "65816"
.segment "CODE"
.org $7247
map_control_0f7247:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
