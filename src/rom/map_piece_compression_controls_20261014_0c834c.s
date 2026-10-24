.setcpu "65816"
.segment "CODE"
.org $834C
map_control_0c834c:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
