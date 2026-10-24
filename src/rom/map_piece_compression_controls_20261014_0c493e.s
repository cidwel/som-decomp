.setcpu "65816"
.segment "CODE"
.org $493E
map_control_0c493e:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
