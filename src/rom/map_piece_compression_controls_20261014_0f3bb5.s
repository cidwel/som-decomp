.setcpu "65816"
.segment "CODE"
.org $3BB5
map_control_0f3bb5:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
