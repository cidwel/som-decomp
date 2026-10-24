.setcpu "65816"
.segment "CODE"
.org $6658
map_control_0f6658:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
