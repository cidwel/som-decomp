.setcpu "65816"
.segment "CODE"
.org $6A19
map_control_0c6a19:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
