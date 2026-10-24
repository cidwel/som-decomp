.setcpu "65816"
.segment "CODE"
.org $6395
map_control_0f6395:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
