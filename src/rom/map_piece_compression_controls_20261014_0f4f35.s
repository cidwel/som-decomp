.setcpu "65816"
.segment "CODE"
.org $4F35
map_control_0f4f35:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
