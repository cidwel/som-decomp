.setcpu "65816"
.segment "CODE"
.org $796C
map_control_0e796c:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
