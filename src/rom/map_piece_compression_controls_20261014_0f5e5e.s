.setcpu "65816"
.segment "CODE"
.org $5E5E
map_control_0f5e5e:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
