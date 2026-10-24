.setcpu "65816"
.segment "CODE"
.org $0889
map_control_0d0889:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
