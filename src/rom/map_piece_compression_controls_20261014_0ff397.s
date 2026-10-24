.setcpu "65816"
.segment "CODE"
.org $F397
map_control_0ff397:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
