.setcpu "65816"
.segment "CODE"
.org $CB66
map_control_0ecb66:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
