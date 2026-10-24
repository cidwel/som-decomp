.setcpu "65816"
.segment "CODE"
.org $6A1A
map_control_0f6a1a:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
