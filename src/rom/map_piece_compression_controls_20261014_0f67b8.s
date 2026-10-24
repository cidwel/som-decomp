.setcpu "65816"
.segment "CODE"
.org $67B8
map_control_0f67b8:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
