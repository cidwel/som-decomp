.setcpu "65816"
.segment "CODE"
.org $0D41
map_control_0f0d41:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
