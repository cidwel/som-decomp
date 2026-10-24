.setcpu "65816"
.segment "CODE"
.org $47B8
map_control_0c47b8:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
