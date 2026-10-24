.setcpu "65816"
.segment "CODE"
.org $6B8B
map_control_0d6b8b:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
