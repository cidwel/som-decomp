.setcpu "65816"
.segment "CODE"
.org $2BEC
map_control_0f2bec:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
