.setcpu "65816"
.segment "CODE"
.org $8165
map_control_0c8165:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
