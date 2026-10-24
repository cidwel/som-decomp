.setcpu "65816"
.segment "CODE"
.org $2B09
map_control_0d2b09:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
