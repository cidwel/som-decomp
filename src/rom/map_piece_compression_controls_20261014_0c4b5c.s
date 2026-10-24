.setcpu "65816"
.segment "CODE"
.org $4B5C
map_control_0c4b5c:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
