.setcpu "65816"
.segment "CODE"
.org $BB5B
map_control_0dbb5b:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
