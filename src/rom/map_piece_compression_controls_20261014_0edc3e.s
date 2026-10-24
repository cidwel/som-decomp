.setcpu "65816"
.segment "CODE"
.org $DC3E
map_control_0edc3e:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
