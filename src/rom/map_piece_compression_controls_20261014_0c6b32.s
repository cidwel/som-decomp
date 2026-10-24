.setcpu "65816"
.segment "CODE"
.org $6B32
map_control_0c6b32:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
